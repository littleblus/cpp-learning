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
		Node* cur = root->_left;
		Node* curright = cur->_right;
		root->_left = curright;
		if (curright)
			curright->_father = root;
		cur->_right = root;
		Node* parent = root->_father;
		root->_father = cur;
		if (parent == nullptr) {
			_root = cur;
			cur->_father = nullptr;
		}
		else {
			if (parent->_left == root)
				parent->_left = cur;
			else // right
				parent->_right = cur;
			cur->_father = parent;
		}
		root->_bf = cur->_bf = 0;
	}

	void rotateL(Node* root) {
		Node* cur = root->_right;
		Node* curleft = cur->_left;
		root->_right = curleft;
		if (curleft)
			curleft->_father = root;
		cur->_left = root;
		Node* parent = root->_father;
		root->_father = cur;
		if (parent == nullptr) {
			_root = cur;
			cur->_father = nullptr;
		}
		else {
			if (parent->_left == root)
				parent->_left = cur;
			else // right
				parent->_right = cur;
			cur->_father = parent;
		}
		root->_bf = cur->_bf = 0;
	}

	void rotateRL(Node* root) {
		Node* cur = root->_right; // ��Ҫ�����Ľڵ㣬��ʱbfΪ-1
		Node* curleft = cur->_left;
		int bf = curleft->_bf;
		rotateR(cur);
		rotateL(root);
		switch (bf) {
		case 0:
			cur->_bf = 0;
			curleft->_bf = 0;
			root->_bf = 0;
			break;
		case 1:
			cur->_bf = 0;
			curleft->_bf = 0;
			root->_bf = -1;
			break;
		case -1:
			cur->_bf = 1;
			curleft->_bf = 0;
			root->_bf = 0;
			break;
		default:
			assert(false);
			break;
		}
	}

	void rotateLR(Node* root) {
		Node* cur = root->_left; // ��Ҫ�����Ľڵ㣬��ʱbfΪ1
		Node* curright = cur->_right;
		int bf = curright->_bf;
		rotateL(cur);
		rotateR(root);
		switch (bf) {
		case 0:
			cur->_bf = 0;
			curright->_bf = 0;
			root->_bf = 0;
			break;
		case 1:
			cur->_bf = -1;
			curright->_bf = 0;
			root->_bf = 0;
			break;
		case -1:
			cur->_bf = 0;
			curright->_bf = 0;
			root->_bf = 1;
			break;
		default:
			assert(false);
			break;
		}
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
			if (bf != root->_bf || abs(bf) > 1) {
				std::cout << "ƽ�������쳣��" << root->_val << " -> " << bf << std::endl;
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
		if (parent == nullptr) {
			_root = cur;
			return true;
		}
		else if (val < parent->_val) {
			parent->_left = cur;
		}
		else {
			parent->_right = cur;
		}
		cur->_father = parent;
		// ά��avl��
		while (parent) {
			// ���� bf
			if (parent->_left == cur)
				parent->_bf--;
			else
				parent->_bf++;
			// ��� bf
			if (parent->_bf == 0)
				break;
			else if (abs(parent->_bf) == 1) {// 1 -1
				cur = parent;
				parent = parent->_father; // �������ϵ���
			}
			else if (parent->_bf == 2) {
				if (cur->_bf == 1)
					rotateL(parent); // ��parent��������
				else if (cur->_bf == -1)
					rotateRL(parent); // ���ҵ�����������
				break;
			}
			else if (parent->_bf == -2) {
				if (cur->_bf == -1)
					rotateR(parent); // ��parent�����ҵ���
				else if (cur->_bf == 1)
					rotateLR(parent); // �����������ҵ���
				break;
			}
			else
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