#include<cstdio>
const int maxn = 100010;
int a[maxn], hashTable[maxn] = {0}; 
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		hashTable[a[i]]++;
	}
	int ans = -1;
	for (int i = 0; i < n; i++) {
		if (hashTable[a[i]] == 1) {
			ans = a[i];
			break;
		} 
	}
	if (ans == -1) {
		printf("None");
	} else
	printf("%d", ans);
	return 0;
}
