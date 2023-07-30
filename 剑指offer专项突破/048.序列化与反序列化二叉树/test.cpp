#include <string>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (!root)
			return "n";
		string left = serialize(root->left);
		string right = serialize(root->right);
		return to_string(root->val) + "," + left + "," + right;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data[0] == 'n') {
			return nullptr;
		}
		// ·Ö¸î×Ö·û´®
		vector<string> vs{""};
		for (auto e : data) {
			if (e == ',') {
				vs.push_back("");
			}
			else {
				vs.back() += e;
			}
		}
		int i = 0;
		return dfs(vs, i);
	}
private:
	TreeNode* dfs(vector<string>& vs, int& i) {
		string str = vs[i++];
		if (str == "n")
			return nullptr;
		TreeNode* root = new TreeNode(stoi(str));
		root->left = dfs(vs, i);
		root->right = dfs(vs, i);
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);
	Codec s;
	string debug = s.serialize(root);
	TreeNode* ret = s.deserialize(debug);

	return 0;
}