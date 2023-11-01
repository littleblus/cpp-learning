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
		typedef K keyType;
		typedef std::pair<const keyType, T> valueType;
	public:

	private:
		RBTree<keyType, valueType, __map_KeyOfT<keyType, valueType>, Comp> _t;
	};
}