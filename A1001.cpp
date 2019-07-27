#include<cstdio>
#include<cstring>
int num[10];
int main() {
	
	int a, b;
	scanf("%d %d", &a, &b);
	int sum = a + b;
	if(sum < 0) {
		printf("-");
		sum = -sum;
	} 
	int len = 0;
	
	if(sum == 0) {
		num[len] = 0;
		len++;
	}
	
	while(sum != 0) {
		num[len] = sum % 10;
		len++;
		sum /= 10;
	}
	
	// 位数决定， 
	for (int k = len - 1; k >= 0; k--) {
		printf("%d", num[k]);
		if(k > 0 && k % 3 == 0) {
			printf(",");
		}
	}


	return 0;
} 
