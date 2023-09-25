#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string input, ret, tmp;
    getline(cin, input);
    for (auto ch : input) {
        if ('0' <= ch && ch <= '9') {
            tmp.push_back(ch);
        }
        else {
            if (tmp.size() > ret.size()) {
                ret = tmp;
            }
            tmp.clear();
        }
    }
    if (tmp.size() > ret.size()) {
        ret = tmp;
    }
    cout << ret << endl;
    return 0;
}

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param numbers int整型vector
	 * @return int整型
	 */
	int MoreThanHalfNum_Solution(vector<int>& numbers) {
		int king = -1;
		int count = 0;
		for (auto e : numbers) {
			if (count == 0)
				king = e;
			if (e == king)
				count++;
			else
				count--;
		}
		return king;
	}
};