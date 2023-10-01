#pragma once

#include "hashTable.h"

using openHash::hashTable;

namespace blus {
	template<class K, class T>
	struct __set_KeyOfT {
		typedef K keyType;
		typedef T valueType;
		keyType operator()(const valueType& val) { return val; }
	};

	template<class K>
	class unordered_set {
		typedef K keyType;
		typedef K valueType;
		typedef typename hashTable<keyType, valueType, __set_KeyOfT<keyType, valueType>>::const_iterator iterator;
		typedef typename hashTable<keyType, valueType, __set_KeyOfT<keyType, valueType>>::const_iterator const_iterator;

	public:
		bool empty() const { return _table.empty(); }
		size_t size() const { return _table.size(); }
		
		bool insert(const valueType& val) {
			return _table.insert(val).second;
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

		iterator begin() { return _table.begin(); }
		const_iterator begin() const { return _table.begin(); }
		iterator end() { return _table.end(); }
		const_iterator end() const { return _table.end(); }
	private:
		hashTable<keyType, valueType, __set_KeyOfT<keyType, valueType>> _table;
	};
}