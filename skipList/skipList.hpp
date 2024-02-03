//
// Created by 10604 on 2024/2/2.
//

#pragma once
#include <vector>
#include <random>
#include <chrono>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

const int P = 37; // percent  P = 1/e * 100 = 37
const int MAX_LEVEL = 32;
std::default_random_engine RAND_GENERATOR(std::chrono::system_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> PERCENT_RAND(0, 100);

static bool prob() { return PERCENT_RAND(RAND_GENERATOR) <= P; }

template<class K, class V, class Comp = std::less<K>>
class skipList {
	struct Node {
		K _key;
		V _val;
		std::vector<Node*> _next;

		Node() = default;
		explicit Node(int level) : _next(level, nullptr) {}
		Node(const K& key, const V& val, int level) : _key(key), _val(val), _next(level, nullptr) {}
	};
public:
	struct const_iterator; // forward declaration
	struct iterator {
		friend struct const_iterator;
		iterator(Node* node) : _node(node) {}
		V& operator*() { return _node->_val; }
		V* operator->() { return &_node->_val; }

		iterator& operator++() {
			_node = _node->_next[0];
			return *this;
		}

		iterator operator++(int) {
			iterator tmp = *this;
			_node = _node->_next[0];
			return tmp;
		}

		bool operator==(const iterator& rhs) const { return _node == rhs._node; }
		bool operator!=(const iterator& rhs) const { return _node != rhs._node; }
	private:
		Node* _node;
	};

	struct const_iterator {
		const_iterator(Node* node) : _node(node) {}
		const_iterator(iterator it) : _node(it._node) {}
		const V& operator*() { return _node->_val; }
		const V* operator->() { return &_node->_val; }

		const_iterator& operator++() {
			_node = _node->_next[0];
			return *this;
		}

		const_iterator operator++(int) {
			const_iterator tmp = *this;
			_node = _node->_next[0];
			return tmp;
		}

		bool operator==(const const_iterator& rhs) const { return _node == rhs._node; }
		bool operator!=(const const_iterator& rhs) const { return _node != rhs._node; }
	private:
		Node* _node;
	};

	inline iterator begin() { return iterator(_head->_next[0]); }
	inline const_iterator begin() const { return const_iterator(_head->_next[0]); }
	inline iterator end() { return iterator(nullptr); }
	inline const_iterator end() const { return const_iterator(nullptr); }

	skipList()
		: _head(new Node(K(), V(), 1))
		, _size(0) {
	}

	iterator find(const K& key) {
		Comp comp;
		Node* cur = _head;
		int level = _head->_next.size() - 1;
		while (level >= 0) {
			if (cur->_next[level] && comp(cur->_next[level]->_key, key)) {
				cur = cur->_next[level];
			}
			else { // cur->_next[level] == nullptr || key <= cur->_next[level]->_key
				--level;
			}
		}
		if (cur->_next[0] && !comp(cur->_next[0]->_key, key) && !comp(key, cur->_next[0]->_key)) {
			return iterator(cur->_next[0]);
		}
		return end();
	}

	const_iterator find(const K& key) const {
		return const_iterator(const_cast<skipList*>(this)->find(key));
	}

	iterator insert(const K& key, const V& val) {
		Comp comp;
		Node* cur(_head);
		std::vector<Node*> prev(_head->_next.size(), nullptr);

		int level = _head->_next.size() - 1;
		while (level >= 0) {
			if (cur->_next[level] && comp(cur->_next[level]->_key, key)) {
				cur = cur->_next[level];
			}
			else { // cur->_next[level] == nullptr || key <= cur->_next[level]->_key
				prev[level] = cur;
				--level;
			}
		}

		int newLevel = 1;
		while (prob() && newLevel < MAX_LEVEL) {
			++newLevel;
		}
		Node* update = new Node(key, val, newLevel);
		if (newLevel > _head->_next.size()) {
			_head->_next.resize(newLevel, update);
		}
		// update the pointers
		int n = std::min(newLevel, static_cast<int>(prev.size()));
		for (int i = 0; i < n; ++i) {
			update->_next[i] = prev[i]->_next[i];
			prev[i]->_next[i] = update;
		}
		++_size;
		return iterator(update);
	}

	bool erase(const K& key) {
		Comp comp;
		Node* cur = _head;
		std::vector<Node*> prev(_head->_next.size(), nullptr);

		int level = _head->_next.size() - 1;
		while (level >= 0) {
			if (cur->_next[level] && comp(cur->_next[level]->_key, key)) {
				cur = cur->_next[level];
			}
			else { // cur->_next[level] == nullptr || key <= cur->_next[level]->_key
				prev[level] = cur;
				--level;
			}
		}
		if (cur->_next[0] && !comp(cur->_next[0]->_key, key) && !comp(key, cur->_next[0]->_key)) {
			Node* toDel = cur->_next[0];
			for (int i = 0; i < toDel->_next.size(); i++) {
				prev[i]->_next[i] = toDel->_next[i];
			}
			delete toDel;
			--_size;
			return true;
		}

		return false;
	}

	[[nodiscard]] size_t size() const { return _size; }

//	void debugPrint() const {
//		Node* cur = _head->_next[0];
//		while (cur) {
//			std::cout << cur->_key << std::endl;
//			for (int i = 0; i < cur->_next.size(); i++) {
//				std::cout << "v";
//			}
//			std::cout << std::endl;
//			cur = cur->_next[0];
//		}
//	}

	~skipList() {
		Node* cur = _head;
		while (cur) {
			Node* tmp = cur;
			cur = cur->_next[0];
			delete tmp;
		}
	}
private:
	Node* _head;
	size_t _size;
};

template<class K>
class SLset {
	using iterator = typename skipList<K, K>::iterator;
	using const_iterator = typename skipList<K, K>::const_iterator;
public:
	iterator begin() { return _data.begin(); }
	const_iterator begin() const { return _data.begin(); }
	iterator end() { return _data.end(); }
	const_iterator end() const { return _data.end(); }

	SLset() = default;
	SLset(const SLset& rhs) {
		for(auto& e : rhs) {
			insert(e);
		}
	}

	SLset(const std::set<K>& rhs) {
		for(auto& e : rhs) {
			insert(e);
		}
	}

	SLset(const std::unordered_set<K>& rhs) {
		for(auto& e : rhs) {
			insert(e);
		}
	}

	iterator find(const K& key) {
		return _data.find(key);
	}

	const_iterator find(const K& key) const {
		return _data.find(key);
	}

	size_t count(const K& key) const {
		size_t cnt = 0;
		for (auto it = find(key); it != end() && *it == key; ++it, ++cnt);
		return cnt;
	}

	iterator insert(const K& key) {
		return _data.insert(key, key);
	}

	bool erase(const K& key) {
		return _data.erase(key);
	}

	[[nodiscard]] size_t size() const {
		return _data.size();
	}

//	void debugPrint() const {
//		_data.debugPrint();
//	}
private:
	skipList<K, K> _data;
};

template<class K, class V>
class SLmap {
	using iterator = typename skipList<K, std::pair<K, V>>::iterator;
	using const_iterator = typename skipList<K, std::pair<K, V>>::const_iterator;
public:
	iterator begin() { return _data.begin(); }
	const_iterator begin() const { return _data.begin(); }
	iterator end() { return _data.end(); }
	const_iterator end() const { return _data.end(); }

	SLmap() = default;
	SLmap(const SLmap& rhs) {
		for(auto& [k, v] : rhs) {
			insert(k, v);
		}
	}

	SLmap(const std::map<K, V>& rhs) {
		for(auto& [k, v] : rhs) {
			insert(k, v);
		}
	}

	SLmap(const std::unordered_map<K, V>& rhs) {
		for(auto& [k, v] : rhs) {
			insert(k, v);
		}
	}

	iterator find(const K& key) {
		return _data.find(key);
	}

	const_iterator find(const K& key) const {
		return _data.find(key);
	}

	V& operator[](const K& key) {
		auto it = find(key);
		return it == end() ? insert(key, V())->second : it->second;
	}

	const V& operator[](const K& key) const {
		auto it = find(key);
		if (it == end()) {
			throw std::out_of_range("Key not found");
		}
		return it->_val;
	}

	size_t count(const K& key) const {
		size_t cnt = 0;
		for (auto it = find(key); it != end() && it->first == key; ++it, ++cnt);
		return cnt;
	}

	iterator insert(const K& key, const V& val) {
		return _data.insert(key, {key, val});
	}

	bool erase(const K& key) {
		return _data.erase(key);
	}

	[[nodiscard]] size_t size() const {
		return _data.size();
	}
private:
	skipList<K, std::pair<K, V>> _data;
};