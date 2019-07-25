#include<cstdio>

bool Judge(int z[], int num) {
	for(int i = 0; i <= num / 2; i++) {
		if(z[i] != z[num - 1 - i]) {
			return false;
		}
	}
	return true;
}
int main() {
	int n, b;
	scanf("%d %d", &n, &b);
	int z[100], num = 0;
	do {
		z[num++] = n % b;
		n /= b;
	} while(n != 0);
	
	bool flag = Judge(z, num);
	if(flag == true) printf("Yes\n");
	else printf("No\n");
	for(int i = num - 1; i >= 0; i--) {
		printf("%d",z[i]);
		if(i != 0) printf(" ");
	}
	return 0; 
} 
