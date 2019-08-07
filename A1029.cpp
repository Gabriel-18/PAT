#include<cstdio>
const int maxn = 1000010;
const int INF = 0x7ffffff;
int s1[maxn], s2[maxn];
// leetcode上好像做过类似的 
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
	// 输出较小的那个 
	// 原因是当到达中位数时，while循环中没有对i j对应的数组元素进行大小比较 
	if (s1[i] < s2[j]) {
		printf("%d\n", s1[i]);
	} else {
		printf("%d\n", s2[j]);
	}
		return 0;
} 
