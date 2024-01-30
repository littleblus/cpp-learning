#pragma once
#include <iostream>


template<class K, size_t M>
struct Node {
	// 方便插入后分裂，多给一个空间
	K _key[M];
	Node* _subs[M + 1];
	Node* _parent = nullptr;
	size_t _size = 0; // 有效元素个数

	Node() {
		memset(_subs, 0, sizeof(_subs)); // nullptr
	}
};

// K是磁盘地址
template<class K, size_t M>
class bTree {
	using Node = Node<K, M>;
private:
	void _insertKey(Node* cur, Node* child, const K& key) {
		int end = cur->_size - 1;
		while (end >= 0) {
			if (key < cur->_key[end]) {
				cur->_key[end + 1] = cur->_key[end];
				cur->_subs[end + 2] = cur->_subs[end + 1];
				--end;
			}
			else {
				break;
			}
		}
		cur->_key[end + 1] = key;
		cur->_subs[end + 2] = child;
		if (child) {
			child->_parent = cur;
		}
		++cur->_size;
	}

	void _inorder(Node* node) {
		if (node == nullptr) {
			return;
		}
		for (int i = 0; i < node->_size; ++i) {
			_inorder(node->_subs[i]);
			std::cout << node->_key[i] << " ";
		}
		_inorder(node->_subs[node->_size]);
	
	}
public:
	// 返回结点以及在结点中的下标，如果没找到，返回父节点和-1
	std::pair<Node*, int> find(const K& key) const {
		Node* cur(_root), * parent(nullptr);
		while (cur) {
			int i = 0;
			while (i < cur->_size) {
				if (cur->_key[i] == key) {
					return { cur,i };
				}
				else if (cur->_key[i] < key) {
					++i;
				}
				else { // key < cur->_key[i]
					break;
				}
			}
			parent = cur;
			cur = cur->_subs[i];
		}
		return { parent,-1 };
	}

	bool insert(const K& key) {
		// 没有根节点
		if (_root == nullptr) {
			_root = new Node;
			_root->_key[0] = key;
			_root->_size = 1;
			return true;
		}
		// 插入的结点一定是在叶子节点
		auto ret = find(key);
		if (ret.second != -1) { // key已经存在，不再插入
			return false;
		}
		Node* cur(ret.first), * child(nullptr);
		K newKey = key;
		while (true) {
			_insertKey(cur, child, newKey);
			// 插入后，如果结点满了，需要分裂
			if (cur->_size == M) {
				Node* bro = new Node;
				int mid = M >> 1;
				// [mid + 1, M - 1]
				for (int i = mid + 1; i < M; ++i) {
					bro->_key[i - mid - 1] = cur->_key[i]; // 转移关键字
					bro->_subs[i - mid - 1] = cur->_subs[i]; // 转移孩子
					if (cur->_subs[i]) { // 更新转移孩子的父亲
						cur->_subs[i]->_parent = bro;
					}
				}
				// 还剩最后一个右孩子
				bro->_subs[M - mid - 1] = cur->_subs[M];
				if (cur->_subs[M]) {
					cur->_subs[M]->_parent = bro;
				}
				bro->_size = M - mid - 1;
				cur->_size = mid; // [0, mid - 1], mid送往父节点
				newKey = cur->_key[mid];
				child = bro;
				// 如果父节点为空，说明cur是根节点，需要新建根节点
				if (cur->_parent == nullptr) {
					Node* root = new Node;
					root->_key[0] = newKey;
					root->_subs[0] = cur;
					root->_subs[1] = child;
					child->_parent = cur->_parent = _root = root;
					root->_size = 1;
					break;
				}
				else {
					cur = cur->_parent;
				}
			}
			else {
				break;
			}
		}
		return true;
	}

	void inorder() {
		_inorder(_root);
		std::cout << std::endl;
	}
private:
	Node* _root = nullptr;
};