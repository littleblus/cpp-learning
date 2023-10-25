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
				// cur为当前节点，prev为父节点，g为祖父节点，u为叔叔节点
				cur = add;
				Node* p = prev, * g = prev->_father;
				Node* u = g->_left == p ? g->_right : g->_left;
				if (g == _pHead) {
					// 这种情况（根节点）为红是不可能的，直接报错
					std::cout << "RBTree error: root is RED!" << std::endl;
					assert(false);
				}
			adjust:
				else if(u && u->_col == RED) {
					// 叔叔节点存在且为红
					// 将父节点和叔叔节点染黑，祖父节点染红
					p->_col = BLACK;
					u->_col = BLACK;
					g->_col = RED;
					// 将祖父节点作为新的插入节点，继续调整
					cur = g;
					p = cur->_father;
					g = p->_father;
					u = g->_left == p ? g->_right : g->_left;
					goto adjust;
				}
				else {
					// 叔叔节点不存在或为黑
					if (p == g->_left) {
						// 父节点为祖父节点的左孩子
						if (cur == p->_left) {
							// 新节点为父节点的左孩子
							// 将父节点染黑，祖父节点染红
							p->_col = BLACK;
							g->_col = RED;
							// 将祖父节点右旋
							g = RotateR(g);
						}
						else {
							// 新节点为父节点的右孩子
							// 将新节点作为父节点，继续调整
							cur = p;
							p = cur->_father;
							g = p->_father;
							// 将父节点左旋
							p = RotateL(p);
							// 将父节点染黑，祖父节点染红
							p->_col = BLACK;
							g->_col = RED;
							// 将祖父节点右旋
							g = RotateR(g);
						}
					}
					else {
						// 父节点为祖父节点的右孩子
						if (cur == p->_right) {
							// 新节点为父节点的右孩子
							// 将父节点染黑，祖父节点染红
							p->_col = BLACK;
							g->_col = RED;
							// 将祖父节点左旋
							g = RotateL(g);
						}
						else {
							// 新节点为父节点的左孩子
							// 将新节点作为父节点，继续调整
							cur = p;
							p = cur->_father;
							g = p->_father;
							// 将父节点右旋
							p = RotateR(p);
							// 将父节点染黑，祖父节点染红
							p->_col = BLACK;
							g->_col = RED;
							// 将祖父节点左旋
							g = RotateL(g);
						}
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