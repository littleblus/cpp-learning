#include <vector>
using namespace std;

class Solution {
	bool setColor(vector<vector<int>>& graph, vector<int>& colors, int i, int color) {
		if (colors[i] != -1)
			return colors[i] == color;
		colors[i] = color; // Ⱦɫ
		for (auto e : graph[i]) {
			if (setColor(graph, colors, e, 1 - color) == false)
				return false;
		}
		return true;
	}
public:
	bool isBipartite(vector<vector<int>>& graph) {
		vector<int> colors(graph.size(), -1);
		for (int i = 0; i < colors.size(); i++) {
			if (colors[i] == -1 && setColor(graph, colors, i, 0) == false)
				return false;
		}
		return true;
	}
};