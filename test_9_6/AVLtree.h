#pragma once
#include <iostream>
#include <assert.h>
#include <queue>

template<class T>
class AVLtree {
	template<class T>
	struct AVLtreeNode {
		AVLtreeNode(const T& val = T())
			: _left(nullptr)
			, _right(nullptr)
			, _father(nullptr)
			, _val(val)
			, _bf(0) {
		}

		T _val;
		AVLtreeNode<T>* _left;
		AVLtreeNode<T>* _right;
		AVLtreeNode<T>* _father;
		int _bf;   // balance factor, right minus left
	};
	typedef AVLtreeNode<T> Node;

	void rotateR(Node* root) {
		assert(root);
		Node* parent = root->_father;
		if (parent == nullptr) {
			// update _root
			_root = root->_left;
			_root->_father = nullptr;
			root->_left = nullptr;
			root->_father = _root;
		}
		else if (parent->_left == root) {
			parent->_left = root->_left;
			parent->_left->_father = parent;
			root->_father = parent->_left;
			root->_left = nullptr;
		}
		else {
			parent->_right = root->_left;
			parent->_right->_father = parent;
			root->_father = parent->_right;
			root->_left = nullptr;
		}
	}

	void rotateL(Node* root) {
		assert(root);
		Node* parent = root->_father;
		if (parent == nullptr) {
			// update _root
			_root = root->_right;
			_root->_father = nullptr;
			root->_right = nullptr;
			root->_father = _root;
		}
		else if (parent->_left == root) {
			parent->_left = root->_right;
			parent->_left->_father = parent;
			root->_father = parent->_left;
			root->_right = nullptr;
		}
		else {
			parent->_right = root->_right;
			parent->_right->_father = parent;
			root->_father = parent->_right;
			root->_right = nullptr;
		}
	}

	void rotateRL(Node* root) {
		Node* tmp = root->_right->_left;
		int& bf = tmp->_bf;
		rotateR(root->_right);
		rotateL(root);
		if (abs(bf) == 1)
			bf *= -1;
	}

	void rotateLR(Node* root) {
		int bf = root->_left->_right->_bf;
		rotateR(root->_left);
		rotateL(root);
		if (abs(bf) == 1)
			bf *= -1;
	}

	void printInorder_core(Node* root) {
		if (root == nullptr)
			return;
		printInorder_core(root->_left);
		std::cout << root->_val << ' ';
		printInorder_core(root->_right);
	}

	bool isAVL_core(Node* root) {
		if (root == nullptr)
			return true;
		else {
			int bf = height(root->_right) - height(root->_left);
			if (abs(bf) > 1) {
				std::cout << "平衡因子异常：" << root->_val << " -> " << bf << std::endl;
				return false;
			}
		}
		return true;
	}

	int height(Node* root) {
		if (root == nullptr)
			return 0;
		else
			return std::max(height(root->_left), height(root->_right)) + 1;
	}
public:
	bool insert(const T& val) {
		Node* cur(_root), *parent(nullptr);
		// find insert pos
		while (cur) {
			parent = cur;
			if (val > cur->_val)
				cur = cur->_right;
			else if (val < cur->_val)
				cur = cur->_left;
			else
				return false;
		}
		// insert
		cur = new Node(val);
		if (parent == nullptr)
			_root = cur;
		else if (val < parent->_val) {
			parent->_left = cur;
		}
		else {
			parent->_right = cur;
		}
		cur->_father = parent;
		// 维护avl树
		while (parent) {
			// 更新 bf
			if (parent->_left == cur)
				parent->_bf--;
			else
				parent->_bf++;
			// 检查 bf
			if (parent->_bf == 0)
				break;
			else if (abs(parent->_bf) == 1) {// 1 -1
				cur = parent;
				parent = parent->_father; // 继续向上调整
			}
			else if (parent->_bf == 2) {
				if (cur->_bf == 1)
					rotateL(parent); // 对parent进行左单旋
				else // -1
					rotateRL(parent); // 先右单旋，再左单旋
				parent->_bf = cur->_bf = 0;
			}
			else if (parent->_bf == -2) {
				if (cur->_bf == -1) // 对parent进行右单旋
					rotateR(parent);
				else // 1
					rotateLR(parent); // 先左单旋，再右单旋
				parent->_bf = cur->_bf = 0;
			}
			else if (abs(parent->_bf) > 2)
				assert(false);
		}

		return true;
	}

	void printInorder() {
		printInorder_core(_root);
		std::cout << std::endl;
	}

	bool isAVL() {
		// bfs
		std::queue<Node*> que;
		que.push(_root);
		while (!que.empty()) {
			Node* cur = que.front();
			que.pop();
			if (isAVL_core(cur) == false)
				return false;
			else {
				if (cur->_left)
					que.push(cur->_left);
				if (cur->_right)
					que.push(cur->_right);
			}
		}
		return true;
	}
private:
	Node* _root = nullptr;
};