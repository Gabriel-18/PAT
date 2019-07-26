#include<cstdio>
int main() {
	char str[90][90];
	int num = 0;
	// 不懂为啥不能在str里面num++ 会导致比实际的长度大一 然后破坏结果？ 
	while(scanf("%s", str[num]) != EOF) {
		num++;
	}
	for(int i = num - 1; i >= 0; i--) {
		printf("%s", str[i]);
		if(i != 0) printf(" ");
	}
	return 0;
} 
