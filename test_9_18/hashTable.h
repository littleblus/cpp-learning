#pragma once
#include <iostream>
#include <string>
#include <vector>

using std::swap;
using std::string;
using std::vector;
using std::cout;
using std::endl;

template<class K>
struct defaultHashFunc {
	typedef K keyVaule;
	size_t operator()(keyVaule key) {
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

namespace closedHash {
	enum STATE {
		EXIST,
		EMPTY,
		DELETE
	};

	template<class T>
	struct hashNode {
		typedef T valueType;
		valueType _val;
		STATE _state = EMPTY;

		explicit hashNode(valueType v = valueType())
			: _val(v) {
		}
	};

	// 闭散列表
	template<class K, class T, class KeyOfT, class hashFunc = defaultHashFunc<K>>
	class hashTable {
	public:
		typedef K keyType;
		typedef T valueType;
		typedef hashNode<valueType> Node;

		explicit hashTable(size_t size = 10) {
			_table = vector<Node>(size);
			_n = 0;
		}

		bool insert(valueType val) {
			KeyOfT kot;
			Node* cur = find(kot(val));
			if (cur && cur->_state == EXIST)
				return false;
			if ((double)_n / _table.size() > 0.75) {
				// 扩容
				//print();
				hashTable newTable(_table.size() * 2);
				for (auto& e : _table) {
					if (e._state == EXIST)
						newTable.insert(e._val);
				}
				swap(*this, newTable);
				//print();
			}
			hashFunc hash;
			keyType key = kot(val);
			size_t hashi = hash(key) % _table.size();
			while (_table[hashi]._state == EXIST) {
				if (hashi == _table.size() - 1)
					hashi = 0;
				else
					hashi++;
			}
			Node newNode = Node(val);
			newNode._state = EXIST;
			_table[hashi] = newNode;
			_n++;
			return true;
		}

		Node* find(keyType key) {
			KeyOfT kot;
			hashFunc hash;
			size_t hashi = hash(key) % _table.size();
			while (_table[hashi]._state == EXIST) {
				if (kot(_table[hashi]._val) == key)
					return &_table[hashi];
				else if (hashi == _table.size() - 1)
					hashi = 0;
				else
					hashi++;
			}
			return nullptr;
		}

		bool erase(keyType key) {
			Node* cur = find(key);
			if (cur) {
				cur->_state = DELETE;
				_n--;
				return true;
			}
			return false;
		}

		void print() {
			for (size_t i = 0; i < _table.size(); i++) {
				printf("[%02zd]", i);
				if(_table[i]._state == EXIST)
					printf("->%d\n", _table[i]._val);
				else
					printf("->null\n");
			}
			printf("\n");
		}
	private:
		vector<Node> _table;
		size_t _n;
	};
}

namespace openHash {
	template<class T>
	struct hashNode {
		typedef T valueType;
		T _val;
		hashNode* _next;

		hashNode(valueType v = valueType(), hashNode* next = nullptr)
			: _val(v)
			, _next(next) {
		}
	};

	template<class K, class T, class KeyOfT, class hashFunc = defaultHashFunc<K>>
	class hashTable {
	public:
		typedef K keyType;
		typedef T valueType;
		typedef hashNode<valueType> Node;

		explicit hashTable(size_t size = 10) {
			_table = vector<Node*>(size, nullptr);
			_n = 0;
		}

		bool insert(valueType val) {
			KeyOfT kot;
			if (find(kot(val)))
				return false;
			hashFunc hash;
			if (_n == _table.size()) {
				// 扩容
				print();
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
			return true;
		}

		Node* find(keyType key) {
			KeyOfT kot;
			hashFunc hash;
			size_t hashi = hash(key) % _table.size();
			if (_table[hashi]) {
				Node* cur = _table[hashi];
				while (cur) {
					if (kot(cur->_val) == key)
						return cur;
					else
						cur = cur->_next;
				}
			}
			return nullptr;
		}

		bool erase(keyType key) {
			hashFunc hash;
			Node* target = find(key);
			if (target) {
				size_t hashi = hash(key) % _table.size();
				Node* prev(nullptr), *cur(_table[hashi]);
				while (cur) {
					if (cur == target)
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

		size_t size() { return _n; }

		void print() {
			for (size_t i = 0; i < _table.size(); i++) {
				printf("[%02zd]", i);
				Node* cur = _table[i];
				while (cur) {
					cout << "->" << cur->_val.first << ':' << cur->_val.second;
					cur = cur->_next;
				}
				cout << "->null" << endl;
			}
			cout << endl;
		}

	private:
		vector<Node*> _table;
		size_t _n;
	};
}