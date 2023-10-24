#pragma once

namespace blus {
	enum color {
		RED,
		BLACK
	};

	template<class T>
	struct RBTreeNode {
		T _val;
		color _col;
		RBTreeNode* _father = nullptr;
		RBTreeNode* _left = nullptr;
		RBTreeNode* _right = nullptr;

		RBTreeNode(const T& val = T(), color col = RED) 
			: _val(val)
			, _col(col)
		{}
	};

	template<class T>
	class RBTree {
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
				// 需要进行旋转
			}
		}

		Node* Find(const T& data);

		Node* LeftMost() {
			return _pHead->_left;
		}

		Node* RightMost() {
			return _pHead->_right;
		}

		bool IsValidRBTRee();
	private:
		bool _IsValidRBTRee(Node* pRoot, size_t blackCount, size_t pathBlack);
		
		void RotateL(Node* pParent);
		
		void RotateR(Node* pParent);
		
		Node*& GetRoot() {
			return _pHead->_father;
		}
	private:
		Node* _pHead;
	};
}