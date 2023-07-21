#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class RandomizedSet {
public:
	/** Initialize your data structure here. */
	RandomizedSet() {
		nums = vector<int>();
		// 哈希表中存放数组中值所对应的下标，以便做到O(1)的删除
		numToPos = unordered_map<int, size_t>();
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		auto it = numToPos.find(val);
		if (it == numToPos.end()) {
			nums.push_back(val);
			numToPos.insert({ val,nums.size() - 1 });
			return true;
		}
		else
			return false;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		auto it = numToPos.find(val);
		if (it == numToPos.end())
			return false;
		else {
			// 注意下标的处理
			size_t pos = it->second;
			swap(nums[pos], nums[nums.size() - 1]);
			numToPos[nums[pos]] = pos;
			nums.pop_back();
			numToPos.erase(it);
			return true;
		}
	}

	/** Get a random element from the set. */
	int getRandom() {
		return nums[rand() % nums.size()];
	}
private:
	vector<int> nums;
	unordered_map<int, size_t> numToPos;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */