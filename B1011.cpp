#include<cstdio>
/**
简单模拟
给的范围超过int 
还有格式问题 
**/ 
int main() {
	int T, tcase = 1;
	scanf("%d", &T);
	
	while(T--) {
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if(a + b > c) {
			printf("Case #%d: true\n", tcase);
		} else {
			printf("Case #%d: false\n", tcase);
		}
		tcase++;
	}
	return 0;
}
