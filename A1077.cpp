#include<cstdio>
#include<cstring>
char str[100][256];
int n, minLen = 256, ans = 0;
int main() {
	scanf("%d", &n);
	getchar();
	
	
	for (int i = 0; i < n; i++) {
		fgets(str[i], 258, stdin);
		int len = strlen(str[i]);
		if (len < minLen) {
			minLen = len;
		}
		
		for (int j = 0; j < len / 2; j++) {
			char temp = str[i][j];
			str[i][j] = str[i][len - 1 - j];
			str[i][len - 1 - j] = temp;
		}
	} 
	
	for (int i = 0; i < minLen; i++) {
		char c = str[0][i];
		bool same = true;
		for (int j = 1; j < n; j++) {
			if (c != str[j][i]) {
				same = false;
				break;
			}
		}
		if(same) ans++;
		else break;
	} 
	
	if (ans) {
		for (int i = ans - 1; i >= 0; i--) {
			printf("%c", str[0][i]);
		} 
	} else {
		printf("nai");
	}
	
	return 0;
} 
