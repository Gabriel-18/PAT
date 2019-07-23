#include <cstdio>
int main() {
	// flag判断有没有输出 
	int a, b, flag = 0;
	while(scanf("%d%d",&a,&b) != EOF) {
		if (b != 0) {
			if(flag == 1) {
				printf(" ");
			}
			printf("%d %d", a * b, b - 1);
			flag = 1;
		}
	} 
	if (flag == 0) {
		printf("0 0");
	}
    return 0;
}

