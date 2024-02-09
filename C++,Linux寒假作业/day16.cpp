#include <vector>

using namespace std;

// 快照数组
// https://leetcode.cn/problems/snapshot-array/description/
class SnapshotArray {
public:
	SnapshotArray(int length) {
		vv.resize(length);
		for (auto& v : vv) {
			v.push_back(0);
		}
	}

	void set(int index, int val) {
		while (vv[index].size() <= cnt) {
			vv[index].push_back(vv[index].back());
		}
		vv[index].back() = val;
	}

	int snap() {
		return cnt++;
	}

	int get(int index, int snap_id) {
		auto& v = vv[index];
		if (v.size() <= snap_id) {
			return v.back();
		}
		else {
			return v[snap_id];
		}
	}
private:
	vector<vector<int>> vv;
	int cnt = 0;
};