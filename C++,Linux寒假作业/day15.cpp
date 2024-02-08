#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 任务调度器
// https://leetcode.cn/problems/task-scheduler/
class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		int taskCnt[26]{}, tl[26]{}, res(0);
		for (auto t : tasks) taskCnt[t - 'A']++;

		for (;;) {
			// 全部任务的等待时间-1
			for (auto& time : tl) if (time > 0) time--;
			// 更新能调度哪个任务的标记
			bool can[26];
			for (int i = 0; i < 26; i++) {
				if (tl[i] > 0) can[i] = false;
				else can[i] = true;
			}
			// 找到能调度任务里面计数最多的
			int maxCnt(-1), pos(0);
			bool over = true;
			for (int i = 0; i < 26; i++) {
				if (can[i] && taskCnt[i] && taskCnt[i] > maxCnt) {
					maxCnt = taskCnt[i];
					pos = i;
				}
				if (taskCnt[i] > 0) over = false;
			}
			if (over) break;
			// 调度
			if (maxCnt != -1) {
				taskCnt[pos]--;
				tl[pos] = n + 1;
			}
			res++;
			// cout << (maxCnt != -1 ? "调度" : "等待") << (char)('A' + pos) << " " << res << endl;
		}
		return res;
	}
};



// 适龄的朋友
// https://leetcode.cn/problems/friends-of-appropriate-ages/description/
class Solution {
public:
	int numFriendRequests(vector<int>& ages) {
		// 0.5*ages[x]+7 < ages[y] ≤ ages[x]
		sort(ages.begin(), ages.end());
		int l(0), r(0), res(0);
		for (auto age : ages) {
			if (age < 15) continue;
			while (ages[l] <= 0.5 * age + 7) l++;
			while (r + 1 < ages.size() && ages[r + 1] <= age) r++;
			res += r - l;
		}
		return res;
	}
};