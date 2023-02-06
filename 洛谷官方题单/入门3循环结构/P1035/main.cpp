#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
    int k;
    scanf("%d", &k);
    double sumSn = 0;
    int n = 0;
    while (sumSn <= k) {
        n++;
        sumSn += 1.0 / n;
    }
    printf("%d\n", n);
    return 0;
}