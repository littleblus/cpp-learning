#pragma once
#include <string>
#include <vector>

using std::swap;
using std::string;
using std::vector;

namespace blus {
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
	template<class K, class T, class kOfT, class hashFunc = defaultHashFunc<K>>
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
			kOfT kot;
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
			kOfT kot;
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