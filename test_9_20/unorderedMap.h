#pragma once

#include "hashTable.h"

using openHash::hashTable;

namespace blus {
	template<class K, class T>
	struct __map_KeyOfT {
		typedef K keyType;
		typedef T valueType;
		keyType operator()(const valueType& val) { return val.first; }
	};

	template<class K, class T>
	class unordered_map {
		typedef K keyType;
		typedef pair<const K, T> valueType;
		typedef typename hashTable<keyType, valueType, __map_KeyOfT<keyType, valueType>>::iterator iterator;
		typedef typename hashTable<keyType, valueType, __map_KeyOfT<keyType, valueType>>::const_iterator const_iterator;

	public:
		bool empty() const { return _table.empty(); }
		size_t size() const { return _table.size(); }

		pair<iterator, bool> insert(const valueType& val) {
			return _table.insert(val);
		}

		bool erase(const keyType& key) {
			return _table.erase(key);
		}

		iterator find(const keyType& key) {
			return _table.find(key);
		}

		const_iterator find(const keyType& key) const {
			return _table.find(key);
		}

		T& operator[](const keyType& key) {
			return _table.insert({ key,T() }).first->second;
		}

		iterator begin() { return _table.begin(); }
		const_iterator begin() const { return _table.begin(); }
		iterator end() { return _table.end(); }
		const_iterator end() const { return _table.end(); }
	private:
		hashTable<keyType, valueType, __map_KeyOfT<keyType, valueType>> _table;
	};
}