#include <iostream>
using namespace std;

// ������
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



// ����С�� N ����������
//https://www.nowcoder.com/practice/9e7a88d6a00e404c8418602515a5046c?tpId=182&&tqId=34812&rp=1&ru=/ta/exam-all&qru=/ta/exam-all/question-ranking
int main() {
	//ŷ��ɸ��
	int n;
	cin >> n;
	bool* isPrime = new bool[n];
	int* Prime = new int[n], count(0);//����Ѿ��жϵ�����
	memset(isPrime, true, sizeof(bool) * (n));//Ĭ�϶�������
	isPrime[0] = isPrime[1] = false;//0��1��������
	for (int i = 2; i < n; i++) {
		if (isPrime[i])//���û��ɸ���ʹ�Ž�ȥ
			Prime[count++] = i;
		//ɸ
		for (int j = 0; j < count && i * Prime[j] < n; j++) {
			isPrime[i * Prime[j]] = false;
			if (i % Prime[j] == 0)//��֤prime[j]Ϊ��С��������ɸȥ�ĺ����պ󲻻��ٱ�ɸ
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