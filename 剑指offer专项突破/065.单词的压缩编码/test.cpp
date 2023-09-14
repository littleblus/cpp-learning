#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

// 反向前缀树
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
		int i = word.size() - 1;
		treeNode* cur = _root;
		while (i >= 0) {
			if (cur->child[word[i] - 'a'] == nullptr) {
				// insert
				cur->child[word[i] - 'a'] = new treeNode(word[i]);
			}
			cur = cur->child[word[i] - 'a'];
			i--;
		}
		cur->isWord = true;
	}

	/** Returns if the word is in the trie. */
	pair<bool, bool> search(string word) {
		int i = word.size() - 1;
		treeNode* cur = _root;
		while (i >= 0) {
			cur = cur->child[word[i] - 'a'];
			i--;
		}
		for (auto e : cur->child) {
			if (e != nullptr)
				return { true,true };
		}
		return { true,false };
	}
private:
	treeNode* _root;
};

class Solution {
public:
	int minimumLengthEncoding(vector<string>& words) {
		// 去重
		unordered_set<string> set;
		for (auto& str : words) {
			set.insert(str);
		}
		Trie rtree;
		// 构建反向前缀树
		for (auto& str : set) {
			rtree.insert(str);
		}
		// 根据反向前缀树构建助记字符串
		int len = 0;
		for (auto& str : set) {
			if (rtree.search(str) == make_pair(true, false))
				len += str.size() + 1;
		}
		return len;
	}
};

int main() {
	vector<string> vs{ "time","time","time" };
	Solution sol;
	cout << sol.minimumLengthEncoding(vs);
	return 0;
}