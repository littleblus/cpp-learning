#pragma once
#include <array>

using std::array;

namespace blus {
	template<size_t N>
	class bitset {
		typedef char Ty;
	public:
		bitset() {
			_map.fill(0);
		}

		void set() {
			_map.fill(1);
		}

		void set(size_t pos, bool val = true) {
			size_t i = pos / (sizeof(Ty) * 8);
			size_t j = pos % (sizeof(Ty) * 8);
			if (val) {
				// 与...0000010000...进行或运算，将对应位置设为1
				_map[i] |= (1 << j);
			}
			else {
				// 与...1111101111...进行与运算，将对应位置设为0
				_map[i] &= ~(1 << j);
			}
		}

		void reset() {
			_map.fill(0);
		}

		void reset(size_t pos) {
			set(pos, false);
		}

		bool test(size_t pos) {
			size_t i = pos / (sizeof(Ty) * 8);
			size_t j = pos % (sizeof(Ty) * 8);
			return (_map[i] >> j) & 1;
		}

		size_t size() { return N; }

		size_t count() {
			size_t count = 0;
			for (size_t i = 0; i < _map.size(); i++) {
				Ty tmp = _map[i];
				for (size_t j = 0; j < sizeof(Ty) * 8; j++) {
					tmp >>= 1;
					count += tmp & 1;
				}
			}
			return count;
		}
	private:
		array<Ty, N / (sizeof(Ty) * 8) + 1> _map;
	};
}