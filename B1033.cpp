#include<cstdio>
#include<cstring>
const int maxn = 100010;
bool hashTable[256];
char str[maxn];
int main() {
	memset(hashTable, true, sizeof(hashTable));
	// 读取失效字符串 
	fgets(str, maxn, stdin);
	int len = strlen(str);
	
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] - 'A' + 'a'; // 大写转小写 
		}
		hashTable[str[i]] = false; // 设置失效 
	}
	
	// 读取欲输入的字符串
	fgets(str, maxn, stdin);
	len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			int low = str[i] - 'A' + 'a'; // 大写转小写 
			if (hashTable[low] == true && hashTable['+'] == true) {
				printf("%c", str[i]); // 输出小写字符 
			} 
		} else if (hashTable[str[i]] == true) {
				printf("%c", str[i]); // 其他字符 
			}
		
	} 
	printf("\n");
	return 0;
}
