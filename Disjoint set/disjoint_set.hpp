#pragma once
#include <vector>

class disjoint_set {
public:
	disjoint_set(std::vector<int>& disjoint_set_vector) : _data(disjoint_set_vector) {}
	disjoint_set(size_t n) { _data.resize(n, -1); }

	size_t element_counts() { return _data.size(); }
	size_t set_counts() {
		int counts = 0;
		for (auto e : _data) {
			if (e < 0) counts++;
		}
		return counts;
	}

	// 如果错误返回0
	size_t setNode_counts(int root) { return _data[root] < 0 ? -_data[root] : 0; }

	int findRoot(int x) {
		// 路径压缩
		if (_data[x] >= 0) {
			_data[x] = findRoot(_data[x]);
		}
		return _data[x] < 0 ? x : _data[x];
	}

	void merge(int a, int b) {
		int roota(findRoot(a)), rootb(findRoot(b));
		if (roota == rootb) return; // 本身就在一个集合没必要合并
		_data[rootb] += _data[roota];
		_data[roota] = rootb;
	}

	bool inSet(int a, int b) { return findRoot(a) == findRoot(b); }
private:
	// 下标的值如果是非负数即为父节点，如果是负数即为根节点，负数的绝对值表示森林的节点个数
	std::vector<int> _data;
};