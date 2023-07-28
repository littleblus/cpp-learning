#pragma once
#include <iostream>

template<class K>
struct BSTreeNode {
	BSTreeNode* _left;
	BSTreeNode* _right;
	K _key;

	BSTreeNode(const K& key)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{}
};

template<class K>
class BSTree {
public:
	typedef BSTreeNode<K> Node;
	BSTree()
		:_root(nullptr)
	{}

	bool insert(const K& key) {
		if (!_root)
			_root = new Node(key);
		Node* parent(nullptr), *cur(_root);
		while (cur) {
			if (key > cur->_key) {
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key) {
				parent = cur;
				cur = cur->_left;
			}
			else
				return false;
		}
		if (key > parent->_key)
			parent->_right = new Node(key);
		else
			parent->_left = new Node(key);
		return true;
	}

	bool erase(const K& key) {
		// 找节点
		Node* parent(nullptr), * cur(_root);
		while (cur) {
			if (key > cur->_key) {
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key) {
				parent = cur;
				cur = cur->_left;
			}
			else { // 找到了
				// 注意：如果root节点就是要删除的，则parent == nullptr
				if (cur->_left == nullptr) {
					if (parent == nullptr)
						_root = cur->_right;
					else if (parent->_left == cur)
						parent->_left = cur->_right;
					else
						parent->_right = cur->_right;
				}
				else if (cur->_right == nullptr) {
					if (parent == nullptr)
						_root = cur->_left;
					else if (parent->_left == cur)
						parent->_left = cur->_left;
					else
						parent->_right = cur->_left;
				}
				else { // 左右都有孩子
					// 找左侧子树的最大值交换
					Node* leftMax = cur->_left;
					parent = cur; // 这里不能是nullptr，防止出现没进循环parent仍为空的情况
					while (leftMax->_right) {
						parent = leftMax;
						leftMax = leftMax->_right;
					}
					std::swap(leftMax->_key, cur->_key);
					if(parent->_left == leftMax)
						parent->_left = nullptr;
					else
						parent->_right = nullptr;
					cur = leftMax;
				}
				delete cur;
				return true;
			}
		}
		// 没找到
		return false;
	}

	Node* find(const K& key) const {
		Node* cur = _root;
		while (cur) {
			if (key < cur->_key)
				cur = cur->_left;
			else if (key > cur->_key)
				cur = cur->_right;
			else // 找到了
				return cur;
		}
		return nullptr;
	}

	void printInOrder() {
		_printInOrder(_root);
		std::cout << std::endl;
	}

private:
	Node* _root;

	void _printInOrder(Node* node) {
		if (node == nullptr)
			return;
		_printInOrder(node->_left);
		std::cout << node->_key << ' ';
		_printInOrder(node->_right);
	}
};