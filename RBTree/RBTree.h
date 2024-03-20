#pragma once
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

		RBTreeNode* sibling() {
			if (!_father) return nullptr;
			if (_father->_left == this) {
				return _father->_right;
			}
			else {
				return _father->_left;
			}
		}
	};

	// K代表key的类型，T代表value的类型（const key、const key-value）
	// keyOfT代表从T中获取key的方法
	// Comp代表比较key的方法
	template<class K, class T, class KeyOfT, class Comp> 
	class RBTree {
	private:
		typedef K keyType;
		typedef T valueType;
		typedef RBTreeNode<T> Node;

		template<class Ref, class Ptr>
		struct __RBTreeIterator {
		public:
			typedef __RBTreeIterator<Ref, Ptr> Self;

			__RBTreeIterator(Node* nptr, const RBTree* tptr) : _node(nptr), _tree(tptr) {}

			Ref operator*() { return _node->_val; }
			Ptr operator->() { return &(_node->_val); }

			Self& operator++() {
				if (_node == _tree->RightMost()) {
					_node = _tree->_pHead; // 回到守卫节点，代表end
				}
				else {
					// 如果有右子树，找右子树的最左侧节点
					if (_node->_right) {
						_node = _node->_right;
						while (_node->_left) {
							_node = _node->_left;
						}
					}
					else {
						// 如果没有右子树，找第一个祖先节点，该节点的左子树包含该节点
						Node* parent = _node->_father;
						while (_node != _tree->_pHead && _node == parent->_right) {
							_node = parent;
							parent = parent->_father;
						}
						_node = parent;
					}
				}
				return *this;
			}

			Self& operator--() {
				if (_node == _tree->_pHead) {
					_node = _tree->RightMost();
				}
				else {
					// 如果有左子树，找左子树的最右侧节点
					if (_node->_left) {
						_node = _node->_left;
						while (_node->_right) {
							_node = _node->_right;
						}
					}
					else {
						// 如果没有左子树，找第一个祖先节点，该节点的右子树包含该节点
						Node* parent = _node->_father;
						while (_node != _tree->_pHead && _node == parent->_left) {
							_node = parent;
							parent = parent->_father;
						}
						_node = parent;
					}
				}
				return *this;
			}

			bool operator==(const Self& it) { return _node == it._node; }
			bool operator!=(const Self& it) { return _node != it._node; }
		private:
			Node* _node;
			const RBTree* _tree;
		};
	public:

		typedef __RBTreeIterator<valueType&, valueType*> iterator;
		typedef __RBTreeIterator<const valueType&, const valueType*> const_iterator;

		RBTree()
			: _pHead(new Node(valueType(), BLACK))
			, _size(0)
			, _isModify(true) {
		}

		iterator begin() { return iterator(LeftMost(), this); }
		const_iterator begin() const { return const_iterator(LeftMost(), this); }
		iterator end() { return iterator(_pHead, this); }
		const_iterator end() const { return const_iterator(_pHead, this); }

		size_t Size() const { return _size; }

		std::pair<iterator, bool> Insert(const valueType& data) {
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
					return { iterator(cur, this), false };
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
			++_size;
			return { iterator(add, this) ,true };
		}

		size_t Erase(const keyType& key) {
			if (delete_child(GetRoot(), key)) {
				--_size;
				_isModify = true;
				return 1;
			}
			else {
				return 0;
			}
		}

		iterator Find(const keyType& key) {
			Comp com;
			KeyOfT kot;
			Node* cur = GetRoot();
			while (cur) {
				if (com(key, kot(cur->_val))) {
					cur = cur->_left;
				}
				else if (com(kot(cur->_val), key)) {
					cur = cur->_right;
				}
				else {
					return iterator(cur, this);
				}
			}
			return end();
		}

		const_iterator Find(const keyType& key) const {
			Comp com;
			KeyOfT kot;
			Node* cur = GetRoot();
			while (cur) {
				if (com(key, kot(cur->_val))) {
					cur = cur->_left;
				}
				else if (com(kot(cur->_val), key)) {
					cur = cur->_right;
				}
				else {
					return const_iterator(cur, this);
				}
			}
			return end();
		}

		Node* LeftMost() const {
			refreshMost();
			return _pHead->_left;
		}

		Node* RightMost() const {
			refreshMost();
			return _pHead->_right;
		}

		bool IsValidRBTree() const {
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

		void PrintInOrder() const {
			_printinorder(GetRoot());
			std::cout << "\n";
		}
	private:
		Node* getSmallestChild(Node* p) {
			if (p->_left == nullptr)
				return p;
			return getSmallestChild(p->_left);
		}

		void swapValueType(valueType& a, valueType& b) {
			if (&a == &b) return;
			// 临时存储用于交换的内存区
			char temp[sizeof(a)];

			// 使用memcpy交换a和b的内容
			std::memcpy(temp, &a, sizeof(a));
			std::memcpy(&a, &b, sizeof(b));
			std::memcpy(&b, temp, sizeof(temp));
		}

		bool delete_child(Node* p, const keyType& key) {
			Comp com;
			KeyOfT kot;
			if (com(key, kot(p->_val))) {
				if (p->_left == nullptr) {
					return false;
				}
				return delete_child(p->_left, key);
			}
			else if (com(kot(p->_val), key)) {
				if (p->_right == nullptr) {
					return false;
				}
				return delete_child(p->_right, key);
			}
			else { // 找到了
				if (p->_right == nullptr) {
					delete_one_child(p);
					return true;
				}
				Node* smallest = getSmallestChild(p->_right);
				// 交换p->_val和smallest->_val, 这两个是pair<const K, V>
				swapValueType(p->_val, smallest->_val);
				delete_one_child(smallest);

				return true;
			}
		}

		void delete_one_child(Node* p) {
			Node* child = p->_left == nullptr ? p->_right : p->_left;
			// child为空, 因为p是叶子节点, 直接删除
			if (!child) {
				if (p->_col == BLACK) {
					delete_case(p);
				}
				if (p->_father) {
					if (p == p->_father->_left) {
						p->_father->_left = nullptr;
					}
					else {
						p->_father->_right = nullptr;
					}
				}
				delete p;
				return;
			}

			if (p->_father == nullptr && p->_left == nullptr && p->_right == nullptr) {
				p = nullptr;
				GetRoot() = p;
				return;
			}

			if (p->_father == nullptr) {
				delete p;
				child->_father = nullptr;
				GetRoot() = child;
				GetRoot()->_col = BLACK;
				return;
			}

			if (p->_father->_left == p) {
				p->_father->_left = child;
			}
			else {
				p->_father->_right = child;
			}
			child->_father = p->_father;

			if (p->_col == BLACK) {
				if (child->_col == RED) {
					child->_col = BLACK;
				}
				else {
					delete_case(child);
				}
			}

			delete p;
		}

		void delete_case(Node* p) {
			if (p == GetRoot()) {
				p->_col = BLACK;
				return;
			}
			// sibling返回空
			if (p->sibling() == nullptr) {
				return;
			}
			if (p->sibling()->_col == RED) {
				p->_father->_col = RED;
				p->sibling()->_col = BLACK;
				if (p == p->_father->_left)
					RotateL(p->_father);
				else
					RotateR(p->_father);
			}
			if (p->sibling() == nullptr) { // 有可能旋转后sibling为空
				return;
			}
			if (p->_father->_col == BLACK && p->sibling()->_col == BLACK
				&& p->sibling()->_left->_col == BLACK && p->sibling()->_right->_col == BLACK) {
				p->sibling()->_col = RED;
				delete_case(p->_father);
			}
			else if (p->_father->_col == RED && p->sibling()->_col == BLACK
				&& p->sibling()->_left->_col == BLACK && p->sibling()->_right->_col == BLACK) {
				p->sibling()->_col = RED;
				p->_father->_col = BLACK;
			}
			else {
				if (p->sibling()->_col == BLACK) {
					if (p == p->_father->_left && p->sibling()->_left->_col == RED
						&& p->sibling()->_right->_col == BLACK) {
						p->sibling()->_col = RED;
						p->sibling()->_left->_col = BLACK;
						RotateR(p->sibling()->_left);
					}
					else if (p == p->_father->_right && p->sibling()->_left->_col == BLACK
						&& p->sibling()->_right->_col == RED) {
						p->sibling()->_col = RED;
						p->sibling()->_right->_col = BLACK;
						RotateL(p->sibling()->_right);
					}
				}
				p->sibling()->_col = p->_father->_col;
				p->_father->_col = BLACK;
				if (p == p->_father->_left) {
					p->sibling()->_right->_col = BLACK;
					RotateL(p->sibling());
				}
				else {
					p->sibling()->_left->_col = BLACK;
					RotateR(p->sibling());
				}
			}
		}

		bool _IsValidRBTree(Node* pRoot, const size_t& blackCount, size_t pathBlack) const {
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

		Node*& GetRoot() const { return _pHead->_father; }

		void _printinorder(Node* root) const {
			if (root == nullptr) return;
			_printinorder(root->_left);
			std::cout << root->_val.second << " ";
			_printinorder(root->_right);
		}

		void refreshMost() const {
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
		size_t _size;
		mutable bool _isModify;
	};
} // namespace blus