#include<cstdio>
const int maxn = 100010;
int school[maxn] = {0};
int main() {
	int n;
	scanf("%d", &n);
	int id, score;
	for(int i = 0; i < n; i++) {
		school[id] += score;
	}
	int max = -1;
	int id1;
	//ע��߽� 
	for(int i = 1; i <= n; i++) {
		if(max < school[i]) {
			max = school[i];
			id1 = i;
		}
	}
	printf("%d %d", id1, max);
	return 0;
} 
