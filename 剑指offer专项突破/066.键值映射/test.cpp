#include <string>
#include <queue>
using namespace std;

struct treeNode {
	treeNode* child[26]{ nullptr };
	int val;
	char ch;

	treeNode(char ch = '\0', int val = 0) :ch(ch), val(val) {}
};

class MapSum {
public:
	/** Initialize your data structure here. */
	MapSum() {
		_root = new treeNode;
	}

	void insert(string key, int val) {
		int i = 0;
		treeNode* cur = _root;
		while (i < key.size()) {
			if (cur->child[key[i] - 'a'] == nullptr) {
				cur->child[key[i] - 'a'] = new treeNode(key[i] - 'a');
			}
			cur = cur->child[key[i] - 'a'];
			i++;
		}
		cur->val = val;
	}

	int sum(string prefix) {
		int i = 0;
		treeNode* cur = _root;
		while (i < prefix.size()) {
			if (cur->child[prefix[i] - 'a'] == nullptr)
				return 0;
			cur = cur->child[prefix[i] - 'a'];
			i++;
		}
		int sum = 0;
		queue<treeNode*> que;
		que.push(cur);
		while (!que.empty()) {
			sum += que.front()->val;
			for (auto e : que.front()->child) {
				if (e != nullptr)
					que.push(e);
			}
			que.pop();
		}
		return sum;
	}
private:
	treeNode* _root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */