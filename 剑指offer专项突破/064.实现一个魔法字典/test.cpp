#include <vector>
#include <string>
using namespace std;

class MagicDictionary {
	bool check_str(string& s1, string& s2) {
		if (s1.size() != s2.size())
			return false;
		int diff = 0;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != s2[i])
				diff++;
			if (diff > 1)
				return false;
		}
		return diff == 1;
	}

	vector<string> _vs;
public:
	/** Initialize your data structure here. */
	MagicDictionary() {}

	void buildDict(vector<string> dictionary) {
		for (auto& str : dictionary) {
			_vs.push_back(str);
		}
	}

	bool search(string searchWord) {
		for (auto& str : _vs) {
			if (check_str(str, searchWord))
				return true;
		}
		return false;
	}
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */