#include<cstdio>
const int N = 100010;
int sum[N];
int n, s, nearS = 100000010;


// s = sum[j] - s[i - 1]

// 返回upper_bound在 【L，r)内第一个大于x的位置 
int upper_bound(int L, int R, int x) {
	int left = L, right = R, mid;
	while (left < right) {
		mid = (right + left) / 2;
		if (sum[mid] > x) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	return left;
}

int main() {
	scanf("%d%d", &n, &s);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}
	
	for (int i = 1; i <= n; i++) {
		int j = upper_bound(i, n + 1, sum[i - 1] + s);
		if (sum[j - 1] - sum[i - 1] == s) {
			nearS = s;
			break;
		} else if (j <= n && sum[j] - sum[i - 1] < nearS) {
			nearS = sum[j] - sum[i - 1];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		int j = upper_bound(i, n + 1,sum[i - 1] + nearS);
		if (sum[j - 1] - sum[i - 1] == nearS) {
			printf("%d-%d\n", i, j - 1);
		}
	}
	return 0;
}
