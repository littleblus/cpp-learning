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
	 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	 *
	 *
	 * @param numbers int����vector
	 * @return int����
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