#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
const int inf = 0x3fffffff;
int a[maxn], leftMax[maxn], rightMin[maxn];
int ans[maxn], num = 0;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	leftMax[0] = 0; //A[0]左边没有比他更大的数 
	for (int i = 0; i < n; i++) {
		leftMax[i] = max(leftMax[i - 1], a[i - 1]);
	}
	
	rightMin[n - 1] = inf; //A[n-1]右边没有比它更小的数
	for (int i = n - 2; i > 0; i--) {
		rightMin[i] = min(rightMin[i + 1], a[i + 1]);
	} 
	
	for (int i = 0; i < n; i++) {
		if (leftMax[i] < a[i] && rightMin[i] > a[i]) {
			ans[num++] = a[i];
		}
	}
	printf("%d\n", num);
	for (int i = 0; i < num; i++) {
		printf("%d", ans[i]);
		if (i < num - 1) printf(" ");
	}
	printf("\n");
	return 0;
}
