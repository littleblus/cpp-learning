#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10000;
int main() {
    int n, q, kase = 0, arr[maxn], x;
    while (scanf("%d%d", &n, &q) == 2 && n != 0) {
        printf("CASE# %d:\n", ++kase);
        for (int i = 0;i < n;i++)
            scanf("%d", &arr[i]);
        sort(arr, arr + n);//升序排序
        for (int i = 0;i < q;i++) {
            scanf("%d", &x);
            int p = lower_bound(arr, arr + n, x) - arr;
            if (arr[p] != x)
                printf("%d not found\n", x);
            else
                printf("%d found at %d\n", x, p + 1);
        }
    }
    return 0;
}