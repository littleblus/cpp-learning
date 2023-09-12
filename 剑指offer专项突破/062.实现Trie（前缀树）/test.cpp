#include <string>
using namespace std;

struct treeNode {
	treeNode* child[26]{ nullptr };
	char ch;
	bool isWord;

	treeNode(char ch = '\0') :ch(ch) ,isWord(false) {}
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
	bool search(string word) {
		size_t i = 0;
		treeNode* cur = _root;
		while (i < word.size()) {
			if (cur->child[word[i] - 'a'] == nullptr)
				return false;
			cur = cur->child[word[i] - 'a'];
			i++;
		}
		return cur->isWord;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		size_t i = 0;
		treeNode* cur = _root;
		while (i < prefix.size()) {
			if (cur->child[prefix[i] - 'a'] == nullptr)
				return false;
			cur = cur->child[prefix[i] - 'a'];
			i++;
		}
		return true;
	}
private:
	treeNode* _root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */