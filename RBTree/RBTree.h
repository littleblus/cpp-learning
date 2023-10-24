#pragma once
#include <assert.h>
#include <iostream>

namespace blus {
	enum color { RED, BLACK };

	template <class T> struct RBTreeNode {
		T			_val;
		color		_col;
		RBTreeNode* _father = nullptr;
		RBTreeNode* _left = nullptr;
		RBTreeNode* _right = nullptr;

		RBTreeNode(const T& val = T(), color col = RED) : _val(val), _col(col) {}
	};

	template <class T> class RBTree {
		typedef RBTreeNode<T> Node;

	public:
		RBTree() {
			_pHead = new Node(T(), BLACK);
			_pHead->_left = _pHead;
			_pHead->_right = _pHead;
		}

		bool Insert(const T& data) {
			Node* cur = GetRoot();
			Node* prev = nullptr;
			// 标志插入的新节点是否是最小或最大
			bool Lflag(true), Rflag(true);
			while (cur) {
				prev = cur;
				if (data < cur->_val) {
					cur = cur->_left;
					Rflag = false;
				}
				else if (cur->_val < data) {
					cur = cur->_right;
					Lflag = false;
				}
				else {
					// 相等，即已存在该节点
					return false;
				}
			}
			// 新的节点
			Node* add = new Node(data);
			if (prev == nullptr) {
				// 没有根节点
				_pHead->_father = add;
				add->_father = _pHead;
				_pHead->_left = add;
				_pHead->_right = add;
			}
			else if (prev->_col == BLACK) {
				if (data < prev->_val) {
					prev->_left = add;
					if (Lflag) {
						_pHead->_left = add;
					}
				}
				else {
					prev->_right = add;
					if (Rflag) {
						_pHead->_right = add;
					}
				}
				add->_father = prev;
			}
			else {
				// 需要进行调整
				if (prev->_father == _pHead) {
					// 这种情况（根节点）为红是不可能的，直接报错
					std::cout << "RBTree error: root is RED!" << std::endl;
					assert(false);
				}
				while (prev->_father != _pHead && prev->_father->_col == RED &&
					prev->_col == RED) {
					// 判断prev兄弟节点的位置
					Node* uncle = prev->_father->_left == prev ?
						prev->_father->_right :
						prev->_father->_left;
					if (uncle->_col == RED) {
						// 情况一：cur为红，prev为红，prev兄弟节点为红，则向上调整
						prev->_col = BLACK;
						uncle->_col = BLACK;
						prev->_father->_col = RED;
						// 向上
						prev = prev->_father;
					}
					else {
						// 情况二：cur为红，prev为红，prev兄弟节点为黑，则需要旋转
						if (prev->_father->_right == uncle) {
							if (prev->_left == cur) {
								// prev在左侧，cur在prev左侧
								RotateR(prev->_father);
								// 调整颜色
								prev->_col = uncle->_col = BLACK;
								prev->_left->_col = prev->_right->_col = RED;
							}
							else {
								// prev在左侧，cur在prev右侧
								prev = RotateL(prev);
								Node* pp = RotateR(prev->_father);
								// 调整颜色
								pp->_col = uncle->_col = BLACK;
								pp->_left->_col = pp->_right->_col = RED;
							}
						}
						else {
							if (prev->_left == cur) {
								// prev在右侧，cur在prev左侧
								prev = RotateR(prev);
								Node* pp = RotateL(prev->_father);
								// 调整颜色
								pp->_col = uncle->_col = BLACK;
								pp->_left->_col = pp->_right->_col = RED;
							}
							else {
								// prev在右侧，cur在prev右侧
								RotateL(prev->_father);
								// 调整颜色
								prev->_col = uncle->_col = BLACK;
								prev->_left->_col = prev->_right->_col = RED;
							}
						}
						// 旋转之后不需要继续向上了，跳出循环
						break;
					}
				}
			}
			// 将根节点颜色归位
			_pHead->_father->_col = BLACK;
			return true;
		}

		Node* Find(const T& data);

		Node* LeftMost() { return _pHead->_left; }

		Node* RightMost() { return _pHead->_right; }

		bool IsValidRBTree();

		void PrintInOrder() {
			_printinorder(GetRoot());
			std::cout << "\n";
		}

	private:
		bool _IsValidRBTree(Node* pRoot, size_t blackCount, size_t pathBlack);

		Node* RotateL(Node* pParent) {
			Node* root = pParent->_right;
			root->_father = pParent->_father;
			pParent->_father = root;
			// 托孤
			pParent->_right = root->_left;
			pParent->_right->_father = pParent;
			root->_left = pParent;
			return root;
		}

		Node* RotateR(Node* pParent) {
			Node* root = pParent->_left;
			root->_father = pParent->_father;
			pParent->_father = root;
			// 托孤
			pParent->_left = root->_right;
			pParent->_left->_father = pParent;
			root->_right = pParent;
			return root;
		}

		Node*& GetRoot() { return _pHead->_father; }

		void _printinorder(Node* root) {
			if (root == nullptr) return;
			_printinorder(root->_left);
			std::cout << root->_val << " ";
			_printinorder(root->_right);
		}
	private:
		Node* _pHead;
	};
}  // namespace blus