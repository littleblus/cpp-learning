#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// 在长度2N的数组中找到重复N次的元素
// https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/
class Solution {
public:
	int repeatedNTimes(vector<int>& nums) {
		unordered_map<int, size_t> numToCount;
		size_t target = nums.size() / 2;
		for (auto e : nums) {
			auto it = numToCount.find(e);
			if (it == numToCount.end()) {
				numToCount.emplace(e, 1);
			}
			else {
				it->second++;
				if (it->second == target)
					return it->first;
			}
		}
		return -1;
	}
};



// 两个数组的交集
// https://leetcode.cn/problems/intersection-of-two-arrays/description/
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> set1(nums1.begin(), nums1.end())
			, set2(nums2.begin(), nums2.end());
		nums1.clear();
		for (int e : set1) {
			if (set2.count(e))
				nums1.emplace_back(e);
		}
		return nums1;
	}
};



// 两个数组的交集II
// https://leetcode.cn/problems/intersection-of-two-arrays-ii/description/
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		vector<int> res;
		int i(0), j(0);
		while (i < nums1.size() && j < nums2.size()) {
			int n1(nums1[i]), n2(nums2[j]);
			if (n1 == n2) {
				res.emplace_back(n1);
				i++, j++;
			}
			else if (n1 > n2)
				j++;
			else
				i++;
		}
		return res;
	}
};



// 两句话中的不常见单词
// https://leetcode.cn/problems/uncommon-words-from-two-sentences/description/
class Solution {
	void mapInit(unordered_map<string, int>& map, const string& s) {
		vector<string> vs;
		vs.emplace_back("");
		for (char ch : s) {
			if (ch == ' ')
				vs.emplace_back("");
			else
				vs.back().push_back(ch);
		}
		for (auto& str : vs) {
			map[str]++;
		}
	}

	void check(unordered_map<string, int>& check, unordered_map<string, int>& map, vector<string>& res) {
		auto it = check.begin();
		while (it != check.end()) {
			if (it->second == 1 && map.count(it->first) == 0)
				res.emplace_back(it->first);
			++it;
		}
	}
public:
	vector<string> uncommonFromSentences(string s1, string s2) {
		unordered_map<string, int> map1, map2;
		mapInit(map1, s1);
		mapInit(map2, s2);
		vector<string> res;
		check(map1, map2, res);
		check(map2, map1, res);
		return res;
	}
};