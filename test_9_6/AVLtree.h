#pragma once
#include <iostream>
#include <assert.h>

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

	void rotateRL(Node* root);

	void rotateLR(Node* root);

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
		if (val < parent->_val) {
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
				// 旋转
				if(cur->_bf == 1)
					rotateL(parent);
				parent->_bf = cur->_bf = 0;
			}
			else if (parent->_bf == -2) {
				if (cur->_bf == -1)
					rotateR(parent);
				parent->_bf = cur->_bf = 0;
			}
			else if (abs(parent->_bf) > 2)
				assert(false);
		}

		return true;
	}
private:
	Node* _root = nullptr;
};