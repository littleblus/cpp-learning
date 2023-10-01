#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;
using std::pair;
using std::swap;
using std::make_pair;

template<class K>
struct defaultHashFunc {
	size_t operator()(size_t key) {
		return key;
	}
};

template<>
struct defaultHashFunc<string> {
	size_t operator()(const string& str) {
		size_t hash = 0;
		for (auto ch : str) {
			hash = hash * 131 + ch;
		}
		return hash;
	}
};

namespace openHash {
	template<class T>
	struct hashNode {
		typedef T valueType;

		valueType _val;
		hashNode* _next;

		hashNode(valueType v = valueType(), hashNode* next = nullptr)
			: _val(v)
			, _next(next) {
		}
	};

	template<class K, class T, class KeyOfT, class hashFunc>
	class hashTable;

	template<class K, class T, class Ref, class Ptr, class KeyOfT, class hashFunc = defaultHashFunc<K>>
	struct __NodeIterator {
		typedef T valueType;
		typedef hashNode<valueType> Node;
		typedef hashTable<K, T, KeyOfT, hashFunc> hashTable;
		typedef __NodeIterator<K, T, T&, T*, KeyOfT, hashFunc> iterator;
		typedef __NodeIterator<K, T, Ref, Ptr, KeyOfT, hashFunc> self;

		const hashTable* _pht;
		Node* _node;

		__NodeIterator(const hashTable* pht, Node* node)
			: _pht(pht)
			, _node(node) {
		}

		__NodeIterator(const iterator& it)
			: _pht(it._pht)
			, _node(it._node) {
		}

		Ref operator*() {
			return _node->_val;
		}

		Ptr operator->() {
			return &_node->_val;
		}

		self& operator++() {
			if (_node->_next) {
				_node = _node->_next;
			}
			else {
				KeyOfT kot;
				hashFunc hash;
				size_t hashi = hash(kot(_node->_val)) % _pht->_table.size();
				hashi++;
				while (hashi < _pht->_table.size()) {
					if (_pht->_table[hashi]) {
						_node = _pht->_table[hashi];
						return *this;
					}
					else {
						hashi++;
					}
				}
				_node = nullptr;
			}
			return *this;
		}

		bool operator!=(const self& other) const {
			return _node != other._node;
		}

		bool operator==(const self& other) const {
			return _node == other._node;
		}
	};

	template<class K, class T, class KeyOfT, class hashFunc = defaultHashFunc<K>>
	class hashTable {
	public:
		typedef K keyType;
		typedef T valueType;
		typedef hashNode<valueType> Node;
		typedef __NodeIterator<K, T, T&, T*, KeyOfT, hashFunc> iterator;
		typedef __NodeIterator<K, T, const T&, const T*, KeyOfT, hashFunc> const_iterator;

		friend iterator;
		friend const_iterator;
		explicit hashTable(size_t size = 10) {
			_table = vector<Node*>(size, nullptr);
			_n = 0;
		}

		~hashTable() {

		}

		pair<iterator, bool> insert(const valueType& val) {
			KeyOfT kot;
			iterator it = find(kot(val));
			if (it != end())
				return make_pair(it, false);
			hashFunc hash;
			if (_n == _table.size()) {
				// 扩容
				vector<Node*> newTable(_n * 2, nullptr);
				for (size_t i = 0; i < _table.size(); i++) {
					while (_table[i]) {
						size_t hashi = hash(kot(_table[i]->_val)) % newTable.size();
						Node* cur = _table[i];
						// 拿下来
						_table[i] = cur->_next;
						// 挂上去
						Node* next = newTable[hashi];
						newTable[hashi] = cur;
						cur->_next = next;
					}
				}
				swap(_table, newTable);
			}
			size_t hashi = hash(kot(val)) % _table.size();
			Node* next = _table[hashi];
			_table[hashi] = new Node(val, next);
			_n++;
			return make_pair(iterator(this, _table[hashi]), true);
		}

		iterator find(const keyType& key) {
			KeyOfT kot;
			hashFunc hash;
			size_t hashi = hash(key) % _table.size();
			if (_table[hashi]) {
				Node* cur = _table[hashi];
				while (cur) {
					if (kot(cur->_val) == key)
						return iterator(this, cur);
					else
						cur = cur->_next;
				}
			}
			return end();
		}

		bool erase(const keyType& key) {
			hashFunc hash;
			iterator target = find(key);
			if (target != end()) {
				size_t hashi = hash(key) % _table.size();
				Node* prev(nullptr), * cur(_table[hashi]);
				while (cur) {
					if (cur == target._node)
						break;
					prev = cur;
					cur = cur->_next;
				}
				if (prev) {
					Node* next = cur->_next;
					delete cur;
					prev->_next = next;
				}
				else {
					_table[hashi] = cur->_next;
				}
				_n--;
				return true;
			}
			return false;
		}

		size_t size() const { return _n; }
		bool empty() const { return _n == 0; }

		iterator begin() {
			for (size_t i = 0; i < _table.size(); i++) {
				if (_table[i])
					return iterator(this, _table[i]);
			}
			return iterator(this, nullptr);
		}
		const_iterator begin() const { return begin(); }

		iterator end() { return iterator(this, nullptr); }
		const_iterator end() const { return const_iterator(this, nullptr); }
	private:
		vector<Node*> _table;
		size_t _n;
	};
}