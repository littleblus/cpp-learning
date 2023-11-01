#pragma once
#include <assert.h>
#include <iostream>

namespace blus {
	enum color { RED, BLACK };

	template<class T>
	struct RBTreeNode {
		T			_val; // 存储的是传进来的valueType
		color		_col;
		RBTreeNode* _father = nullptr;
		RBTreeNode* _left = nullptr;
		RBTreeNode* _right = nullptr;

		RBTreeNode(const T& val = T(), color col = RED) : _val(val), _col(col) {}
	};

	template<class K, class T, class KeyOfT, class Comp> 
	class RBTree {
		typedef RBTreeNode<T> Node;

	public:
		RBTree()
			: _pHead(new Node(T(), BLACK))
			, _isModify(true) {
		}

		std::pair<Node*, bool> Insert(const T& data) {
			Comp com;
			KeyOfT kot;
			Node* cur = GetRoot();
			Node* prev = nullptr;
			// 标志插入的新节点是否是最小或最大
			while (cur) {
				prev = cur;
				if (com(kot(data), kot(cur->_val))) {
					cur = cur->_left;
				}
				else if (com(kot(cur->_val), kot(data))) {
					cur = cur->_right;
				}
				else {
					// 相等，即已存在该节点
					return { cur,false };
				}
			}
			// 新的节点，颜色默认为红色
			Node* add = new Node(data);
			cur = add;
			if (prev == nullptr) {
				// 没有根节点
				_pHead->_father = add;
				add->_father = _pHead;
			}
			else {
				// 挂载节点
				if (com(kot(data), kot(prev->_val))) {
					prev->_left = add;
				}
				else {
					prev->_right = add;
				}
				add->_father = prev;
			}
			while (prev && prev->_col == RED) {
				Node* grandfather = prev->_father;
				if (prev == grandfather->_left) {
					Node* uncle = grandfather->_right;
					if (uncle && uncle->_col == RED) {
						// 叔叔节点存在且为红色
						// 将父节点和叔叔节点染黑，祖父节点染红
						prev->_col = uncle->_col = BLACK;
						grandfather->_col = RED;
						// 继续向上判断
						cur = grandfather;
						prev = cur->_father;
					}
					else {
						// 叔叔节点不存在或为黑色
						if (cur == prev->_right) {
							// 新节点为父节点的右子树，左旋
							RotateL(prev);
						}
						// 新节点为父节点的左子树，右旋
						grandfather = RotateR(grandfather);
						// 将原父节点染黑，原祖父节点染红
						grandfather->_col = BLACK;
						grandfather->_right->_col = RED;
						// 跳出循环
						break;
					}
				}
				else { // prev == grandfather->_right
					Node* uncle = grandfather->_left;
					if (uncle && uncle->_col == RED) {
						// 叔叔节点存在且为红色
						// 将父节点和叔叔节点染黑，祖父节点染红
						prev->_col = uncle->_col = BLACK;
						grandfather->_col = RED;
						// 继续向上判断
						cur = grandfather;
						prev = cur->_father;
					}
					else {
						// 叔叔节点不存在或为黑色
						if (cur == prev->_left) {
							// 新节点为父节点的左子树，右旋
							RotateR(prev);
						}
						// 新节点为父节点的右子树，左旋
						grandfather = RotateL(grandfather);
						// 将原父节点染黑，原祖父节点染红
						grandfather->_col = BLACK;
						grandfather->_right->_col = RED;
						// 跳出循环
						break;
					}
				}
			}
			// 将根节点颜色归位
			_pHead->_father->_col = BLACK;
			_isModify = true;
			return { add,true };
		}

		Node* Find(const T& data) {
			Node* cur = GetRoot();
			while (cur) {
				if (data < cur->_val) {
					cur = cur->_left;
				}
				else if (cur->_val < data) {
					cur = cur->_right;
				}
				else {
					return cur;
				}
			}
			return nullptr;
		}

		Node* LeftMost() {
			refreshMost();
			return _pHead->_left;
		}

		Node* RightMost() {
			refreshMost();
			return _pHead->_right;
		}

		bool IsValidRBTree() {
			Node* root = GetRoot();
			if (!root) return true;
			if (root->_col == RED) return false;
			// 查出一条路径的blackCount（最左侧）
			size_t blackCount = 0;
			Node* cur = root;
			while (cur) {
				if (cur->_col == BLACK) {
					++blackCount;
				}
				cur = cur->_left;
			}
			return _IsValidRBTree(root, blackCount, 0);
		}

		void PrintInOrder() {
			_printinorder(GetRoot());
			std::cout << "\n";
		}

	private:
		bool _IsValidRBTree(Node* pRoot, const size_t& blackCount, size_t pathBlack) {
			// 判断是否是红黑树
			if (pRoot == nullptr) {
				if (blackCount == pathBlack) {
					return true;
				}
				return false;
			}
			if (pRoot->_col == BLACK) {
				++pathBlack;
			}
			else if (pRoot->_father == RED) {
				// 红色节点的父节点不能为红色
				return false;
			}
			if (pRoot->_left && pRoot->_left->_val > pRoot->_val) {
				return false;
			}
			if (pRoot->_right && pRoot->_right->_val < pRoot->_val) {
				return false;
			}
			return _IsValidRBTree(pRoot->_left, blackCount, pathBlack) &&
				   _IsValidRBTree(pRoot->_right, blackCount, pathBlack);
		}

		Node* RotateL(Node* pParent) {
			Node* root = pParent->_right;
			pParent->_right = root->_left; // 托孤,nullptr也可以
			if (root->_left)
				root->_left->_father = pParent; // 更新孤儿的父节点
			Node* ppnode = pParent->_father;
			// 旋转
			root->_left = pParent;
			pParent->_father = root;
			// 挂载到父节点上
			if (pParent == GetRoot()) {
				GetRoot() = root;
				root->_father = _pHead;
			}
			else {
				if (pParent == ppnode->_left)
					ppnode->_left = root;
				else
					ppnode->_right = root;
				root->_father = ppnode;
			}
			return root;
		}

		Node* RotateR(Node* pParent) {
			Node* root = pParent->_left;
			pParent->_left = root->_right; // 托孤,nullptr也可以
			if (root->_right)
				root->_right->_father = pParent; // 更新孤儿的父节点
			Node* ppnode = pParent->_father;
			// 旋转
			root->_right = pParent;
			pParent->_father = root;
			// 挂载到父节点上
			if (pParent == GetRoot()) {
				GetRoot() = root;
				root->_father = _pHead;
			}
			else {
				if (pParent == ppnode->_left)
					ppnode->_left = root;
				else
					ppnode->_right = root;
				root->_father = ppnode;
			}
			return root;
		}

		Node*& GetRoot() { return _pHead->_father; }

		void _printinorder(Node* root) {
			if (root == nullptr) return;
			_printinorder(root->_left);
			std::cout << root->_val.second << " ";
			_printinorder(root->_right);
		}

		void refreshMost() {
			if (_isModify) {
				Node* root = GetRoot();
				Node* cur = root;
				while (cur->_left) {
					cur = cur->_left;
				}
				_pHead->_left = cur;
				cur = root;
				while (cur->_right) {
					cur = cur->_right;
				}
				_pHead->_right = cur;
				_isModify = false;
			}
		}
	private:
		Node* _pHead;
		bool _isModify;
	};
}  // namespace blus