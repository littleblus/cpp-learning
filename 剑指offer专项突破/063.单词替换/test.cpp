#include <string>
#include <vector>
using namespace std;

struct treeNode {
	treeNode* child[26]{ nullptr };
	char ch;
	bool isWord;

	treeNode(char ch = '\0') :ch(ch), isWord(false) {}
};

class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		_root = new treeNode;
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		size_t i = 0;
		treeNode* cur = _root;
		while (i < word.size()) {
			if (cur->child[word[i] - 'a'] == nullptr) {
				// insert
				cur->child[word[i] - 'a'] = new treeNode(word[i]);
			}
			cur = cur->child[word[i] - 'a'];
			i++;
		}
		cur->isWord = true;
	}

	/** Returns if the word is in the trie. */
	pair<bool, bool> search(string word) {
		size_t i = 0;
		treeNode* cur = _root;
		while (i < word.size()) {
			if (cur->child[word[i] - 'a'] == nullptr)
				return { false,false };
			cur = cur->child[word[i] - 'a'];
			i++;
		}
		return { true,cur->isWord };
	}
private:
	treeNode* _root;
};

class Solution {
public:
	string replaceWords(vector<string>& dictionary, string sentence) {
		Trie tree;
		// 构建前缀树
		for (auto& str : dictionary) {
			tree.insert(str);
		}
		vector<string> vSen;
		vSen.push_back("");
		// 分割字符串
		for (auto e : sentence) {
			if (e == ' ')
				vSen.push_back("");
			else
				vSen.back().push_back(e);
		}
		for (auto& str : vSen) {
			string tmp;
			for (auto ch : str) {
				tmp.push_back(ch);
				if (tree.search(tmp) == make_pair(false, false))
					break;
				else if (tree.search(tmp) == make_pair(true, true)) {
					str = tmp;
					break;
				}
			}
		}
		// 构建返回字符串
		string ret;
		for (auto it = vSen.begin(); it != vSen.end() - 1; it++) {
			ret += *it + ' ';
		}
		ret += *(vSen.end() - 1);
		return ret;
	}
};

int main() {
	Solution sol;
	vector<string> vs{ "cat","bat","rat" };
	sol.replaceWords(vs, "the cattle was rattled by the battery");
	return 0;
}