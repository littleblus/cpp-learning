#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// 日期转换
int main() {
    int y, m, d, res(0);
    cin >> y >> m >> d;
    bool isLeapYear = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
    int days[13]{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    for (int i = 1; i < m; i++) {
        res += days[i];
    }
    res += d;
    if (isLeapYear && (m > 2 || (m == 2 && d == 29))) {
        res++;
    }
    cout << res << endl;
    return 0;
}



// 幸运的袋子

using LL = long long;
int N, bag[1002];
LL res(0), sum(0), proc(1);

void dfs(int index) {
    for (int i = index; i < N; i++) {
        sum += bag[i];
        proc *= bag[i];
        if (sum > proc) {
            res++;
            dfs(i + 1);
        }
        else if (bag[i] == 1) {
            dfs(i + 1);
        }
        else {
            sum -= bag[i];
            proc /= bag[i];
            break;
        }
        sum -= bag[i];
        proc /= bag[i];
        for (; i < N - 1 && bag[i] == bag[i + 1]; i++);
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", bag + i);
    sort(bag, bag + N);
    dfs(0);
    printf("%lld\n", res);
    return 0;
}