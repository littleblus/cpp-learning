#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
	double dfs(unordered_map<string, unordered_map<string, double>>& map,
		unordered_set<string>& visited,
		const string& begin, const string& end, double cur) {
		if (begin == end) // �����յ�
			return cur;
		visited.emplace(begin); // ��Ƿ���
		for (auto& strAndVal : map[begin]) {
			if (!visited.count(strAndVal.first)) { // ��û�߹��ģ�����ɻ�
				double ret = dfs(map, visited, strAndVal.first, end, cur * strAndVal.second);
				if (abs(ret + 1) > 1e-6) // ��Ϊ-1.0��return
					return ret;
			}
		}
		return -1.0;
	}
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		unordered_map<string, unordered_map<string, double>> map;
		for (size_t i = 0; i < equations.size(); i++) {
			string& s1 = equations[i][0];
			string& s2 = equations[i][1];
			map[s1].emplace(s2, values[i]);
			map[s2].emplace(s1, 1.0 / values[i]);
		}
		vector<double> ret;
		for (auto& e : queries) {
			if (!map.count(e[0]) || !map.count(e[1])) // ������
				ret.emplace_back(-1.0);
			else if (e[0] == e[1])
				ret.emplace_back(1.0);
			else {
				unordered_set<string> visited;
				ret.emplace_back(dfs(map, visited, e[0], e[1], 1.0));
			}
		}
		return ret;
	}
};