#include<cstdio>
#include<cstring>
int main() {
	//100位远超long long 只能用字符串处理 
	char str[110];
	scanf("%s", &str);
	int len = strlen(str);
	int sum = 0;
	for(int i = 0; i < len; i++) {
		sum += str[i] - '0';
	}
	
	int num = 0, ans[11];
	while(sum != 0) {
		ans[num++] = sum % 10;
		sum /= 10;
	}
	char change[10][6] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	for(int i = num - 1; i >= 0; i--) {
		printf("%s", change[ans[i]]);
		if(i != 0) printf(" ");
	}
	return 0;
}
