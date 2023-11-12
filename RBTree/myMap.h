#pragma once
#include "RBTree.h"

namespace blus {
	template<class K, class T>
	struct __map_KeyOfT {
		typedef K keyType;
		typedef T valueType;
		keyType operator()(const valueType& val) { return val.first; }
	};

	template<class K, class T, class Comp = std::less<T>>
	class map {
	public:
		typedef K keyType;
		typedef std::pair<const keyType, T> valueType;
		typedef typename RBTree<keyType, valueType, __map_KeyOfT<keyType, valueType>, Comp>::iterator iterator;
		typedef typename RBTree<keyType, valueType, __map_KeyOfT<keyType, valueType>, Comp>::const_iterator const_iterator;

		iterator begin() { return _t.begin(); }
		iterator end() { return _t.end(); }
		const_iterator begin() const { return _t.begin(); }
		const_iterator end() const { return _t.end(); }

		T& operator[](const keyType& key) {
			return (_t.Insert(std::make_pair(key, T())).first)->second;
		}

		const T& operator[](const keyType& key) const {
			return find(key)->second;
		}

		std::pair<iterator, bool> insert(const valueType& val) {
			return _t.Insert(val);
		}

		iterator find(const keyType& key) {
			return _t.Find(key);
		}

		const_iterator find(const keyType& key) const {
			return _t.Find(key);
		}
	private:
		RBTree<keyType, valueType, __map_KeyOfT<keyType, valueType>, Comp> _t;
	};
}