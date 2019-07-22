#include<cstdio>
/*
简单模拟 
如果它是偶数，那么把它砍掉一半；
如果它是奇数，那么把 (3n+1) 砍掉一半
最后一定在某一步得到 n=1
*/
int main() {
	int n, step = 0;
	scanf("%d", &n);
	while(n != 1) {
		if(n % 2 == 0) n = n / 2;
		else n = (3 * n + 1) / 2;
		step++;
	}
	printf("%d\n", step);
	return 0;
} 
