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
		// �ҽڵ�
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
			else { // �ҵ���
				// ע�⣺���root�ڵ����Ҫɾ���ģ���parent == nullptr
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
				else { // ���Ҷ��к���
					// ��������������ֵ����
					Node* leftMax = cur->_left;
					parent = cur; // ���ﲻ����nullptr����ֹ����û��ѭ��parent��Ϊ�յ����
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
		// û�ҵ�
		return false;
	}

	Node* find(const K& key) const {
		Node* cur = _root;
		while (cur) {
			if (key < cur->_key)
				cur = cur->_left;
			else if (key > cur->_key)
				cur = cur->_right;
			else // �ҵ���
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