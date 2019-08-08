#include<cstdio>
#include<cstring>
const int maxn = 100010;
const int mod = 1000000007;
char str[maxn];
int leftNumP[maxn] = {0};
int main() {
	fgets(str, maxn, stdin);
	int len = strlen(str);
	
	for (int i = 0; i < len; i++) {
		if (i > 0) { // 如果不是0号 
			leftNumP[i] = leftNumP[i - 1];
		} 
		if (str[i] == 'P') { // 当前位是P 
			leftNumP[i]++;
		}
	}
	// rightNumT记录右边T的个数 
	int ans = 0, rightNumT = 0;
	for (int i = len - 1; i >= 0; i--) {
		if (str[i] == 'T') {
			rightNumT++;
		} else if (str[i] == 'A') {
			//求和好好理解下 
		ans = (ans + leftNumP[i] * rightNumT) % mod; 
	}
}
	printf("%d\n", ans);
	return 0;
} 
