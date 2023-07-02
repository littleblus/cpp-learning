#include <vector>
#include <unordered_map>
using namespace std;
class NumMatrix {
public:
	NumMatrix(vector<vector<int>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		// 创建指向指针的指针数组
		a = new int*[row];
		// 为每个指针分配内存空间
		for (int i = 0; i < row; i++) {
			a[i] = new int[col];
		}
		//复制值
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				a[i][j] = matrix[i][j];
			}
		}
		//进行预求和
		partSum(row, col);
	}

	void partSum(int row, int col) {
		part = new int* [row];
		for (int i = 0; i < row; i++) {
			part[i] = new int[col];
		}
		//对每个位置的左上区域求和
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				part[i][j] = a[i][j] + (i - 1 >= 0 ? part[i - 1][j] : 0) + (j - 1 >= 0 ? part[i][j - 1] : 0)
					- (i - 1 >= 0 && j - 1 >= 0 ? part[i - 1][j - 1] : 0);
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return part[row2][col2] - (row1 - 1 >= 0 ? part[row1 - 1][col2] : 0) - (col1 - 1 >= 0 ? part[row2][col1 - 1] : 0)
			+ (row1 - 1 >= 0 && col1 - 1 >= 0 ? part[row1 - 1][col1 - 1] : 0);
	}
private:
	int** a;
	int** part;
};

int main() {
	vector<vector<int>>t{{3, 0, 1, 4, 2}, { 5,6,3,2,1 }, { 1,2,0,1,5 }, { 4,1,0,1,7 }, { 1,0,3,0,5 }};
	NumMatrix s(t);
	//int r = s.sumRegion(2, 1, 4, 3);
	return 0;
}