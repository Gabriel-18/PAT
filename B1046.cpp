#include<cstdio>
// 双重条件验证 
int main() {
	int N;
	int failA = 0, failB = 0;
	scanf("%d", &N);
	while(N--) {
		int a1, a2, b1, b2;
		scanf("%d%d%d%d", &a1,&a2,&b1,&b2);
		if(a1 + b1 == a2 && a1 + b1 != b2) {
			failB++;
		} else if(a1 + b1 != a2 && a1 + b1 == b2){
			failA++;
		}
	}
	printf("%d %d", failA, failB);
	return 0;
} 
