#include<cstdio>
#include<cstring>
const int maxn = 110;
char A[maxn] , B[maxn], ans[maxn] = {0};
void reverse(char s[]) {
	int len = strlen(s);
	// 跟交换两数的思路一致 
	for(int i = 0; i < len / 2; i++) {
		int temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	} 
}
int main() {
	scanf("%s %s", &A, &B);
	reverse(A); 
	reverse(B);
	int len1 = strlen(A);
	int len2 = strlen(B);
	int len = len1 > len2 ? len1 : len2;
	for(int i = 0; i < len; i++) {
		int num1 = i < len1 ? A[i] - '0' : 0;
		int num2 = i < len2 ? B[i] - '0' : 0;
		if (i % 2 == 0) { 
		// 这里的对13取余 暗示一共13位编码 
			int temp = (num1 + num2) % 13;
			if (temp == 10) ans[i] = 'J';
			else if (temp == 11) ans[i] = 'Q'; 
			else if (temp == 12) ans[i] = 'K';
			else ans[i] = temp + '0'; // 0 - 9 
		} else {
			int temp = num2 - num1;
			if(temp < 0) temp += 10;
			ans[i] = temp + '0';
		}
	} 
	reverse(ans);
	fputs(ans, stdout);
	return 0; 
}
