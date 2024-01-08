#include <iostream>
#include <vector>
#include <unordered_map>

template<typename V, typename W, bool directed = false, W W_MAX = INT_MAX>
class graph {
private:
	void _graph(const std::vector<V>& vertex) {
		_vertex = vertex;
		size_t i = 0;
		for (auto& e : vertex) {
			_indexMap[e] = i++;
		}
		_matrix.reserve(vertex.size());
		for (size_t i = 0; i < vertex.size(); i++) {
			_matrix.emplace_back(std::vector<W>(vertex.size(), W_MAX));
		}
	}
public:
	graph() = delete;

	graph(const V* varr, size_t n) {
		std::vector<V> vertex(varr, varr + n);
		_graph(vertex);
	}

	graph(const std::vector<V>& vertex) { _graph(vertex); }

	size_t getVertexIndex(const V& v) {
		auto it = _indexMap.find(v);
		if (it != _indexMap.end()) {
			return it->second;
		}
		else {
			return -1;
		}
	}

	void addSingleEdge(const V& src, const V& dest, const W& weight) {
		size_t srci(getVertexIndex(src)), desti(getVertexIndex(dest));
		_matrix[srci][desti] = weight;
	}

	void addEdge(const V& src, const V& dest, const W& weight) {
		size_t srci(getVertexIndex(src)), desti(getVertexIndex(dest));
		_matrix[srci][desti] = weight;
		if (directed == false) {
			_matrix[desti][srci] = weight;
		}
	}
private:
	std::vector<V> _vertex;
	std::unordered_map<V, size_t> _indexMap;
	std::vector<std::vector<W>> _matrix;
};
