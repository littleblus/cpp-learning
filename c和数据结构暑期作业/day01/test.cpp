#include <iostream>
using namespace std;

// 自守数
//https://www.nowcoder.com/practice/88ddd31618f04514ae3a689e83f3ab8e?tpId=37&&tqId=21322&rp=1&ru=/ta/huawei&qru=/ta/huawei/question-ranking
//int main() {
//	int n, sum(0);
//	cin >> n;
//	for (int i = 0; i <= n; i++) {
//		int mod;
//		if (i < 10)
//			mod = 10;
//		else if (i < 100)
//			mod = 100;
//		else if (i < 1000)
//			mod = 1000;
//		else if (i < 10000)
//			mod = 10000;
//		else if (i < 100000)
//			mod = 100000;
//		if ((i * i - i) % mod == 0)
//			sum++;
//	}
//	cout << sum << endl;
//	return 0;
//}



// 返回小于 N 的质数个数
//https://www.nowcoder.com/practice/9e7a88d6a00e404c8418602515a5046c?tpId=182&&tqId=34812&rp=1&ru=/ta/exam-all&qru=/ta/exam-all/question-ranking
int main() {
	//欧拉筛法
	int n;
	cin >> n;
	bool* isPrime = new bool[n];
	int* Prime = new int[n], count(0);//存放已经判断的质数
	memset(isPrime, true, sizeof(bool) * (n));//默认都是质数
	isPrime[0] = isPrime[1] = false;//0和1不是质数
	for (int i = 2; i < n; i++) {
		if (isPrime[i])//如果没被筛掉就存放进去
			Prime[count++] = i;
		//筛
		for (int j = 0; j < count && i * Prime[j] < n; j++) {
			isPrime[i * Prime[j]] = false;
			if (i % Prime[j] == 0)//保证prime[j]为最小质因数，筛去的合数日后不会再被筛
				break;
		}
	}
	int res = 0;
	for (int i = 1; i < n; i++) {
		if (isPrime[i])
			res++;
	}
	cout << res << endl;
	return 0;
}