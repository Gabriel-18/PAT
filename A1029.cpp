#include<cstdio>
const int maxn = 1000010;
const int INF = 0x7ffffff;
int s1[maxn], s2[maxn];
// leetcode�Ϻ����������Ƶ� 
int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &s1[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &s2[i]);
	}
	
	s1[n] = s2[m] = INF;
	int medianPos = (m + n - 1) / 2;
	int i = 0, j = 0, count = 0;
	while (count < medianPos) {
		if (s1[i] < s2[j]) i++;
		else j++;
		count++;
	}
	// �����С���Ǹ� 
	// ԭ���ǵ�������λ��ʱ��whileѭ����û�ж�i j��Ӧ������Ԫ�ؽ��д�С�Ƚ� 
	if (s1[i] < s2[j]) {
		printf("%d\n", s1[i]);
	} else {
		printf("%d\n", s2[j]);
	}
		return 0;
} 
