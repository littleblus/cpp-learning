#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

const int maxn = 25;
vector <int> pile[maxn];
int n;

void find_pos(int x, int& p, int& h) {
	for (p = 0; p < n; p++) {
		for (h = 0; h < pile[p].size(); h++) {
			if (x == pile[p][h])
				return;
		}
	}
}

void clear(int px, int hx) {
	for (int h = hx + 1; h < pile[px].size(); h++) {
		int pz = pile[px][h];
		pile[pz].push_back(pz);
	}
	pile[px].resize(hx + 1);
}

void pile_over(int pa, int ha, int pb) {
	for (int h = ha; h < pile[pa].size(); h++) {
		pile[pb].push_back(pile[pa][h]);
	}
	pile[pa].resize(ha);
}

void print() {
	for (int p = 0; p < n; p++) {
		printf("%d:", p);
		for (int h = 0; h < pile[p].size(); h++) {
			printf(" %d", pile[p][h]);
		}
		printf("\n");
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	cin >> n;
	//初始化木块
	for (int i = 0; i < n; i++) {
		pile[i].push_back(i);
	}
	string str1, str2;
	int a, b;
	while (cin >> str1 >> a >> str2 >> b) {
		int pa, pb, ha, hb;
		find_pos(a, pa, ha);
		find_pos(b, pb, hb);
		if (pa == pb)//a，b同一堆，非法操作
			continue;
		if (str1 == "move")
			clear(pa, ha);
		if (str2 == "onto")
			clear(pb, hb);
		pile_over(pa, ha, pb);
	}
	print();
	return 0;
}