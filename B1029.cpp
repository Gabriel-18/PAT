#include<cstdio>
#include<cstring>
int main() {
	char str1[100], str2[100];
	bool HashTable[128] = {false};
	fgets(str1, 100, stdin);
	fgets(str2, 100, stdin);
	
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	for (int i = 0; i < len1; i++) { // 枚举第一个字符串里面的字符 
		int j;
		char c1, c2;
		// 目标 找出不存的 
		for (j = 0; j < len2; j++) { // 枚举第二个字符串里面的字符 
			c1 = str1[i];
			c2 = str2[j];
			if (c1 >= 'a' && c1 <= 'z') c1 -= 32;
			if (c2 >= 'a' && c2 <= 'z') c2 -= 32;
			if (c1 == c2) break; // 第二个字符串中如果存在c1, 则跳出 
		}
		
		if (j == len2 && HashTable[c1] == false) {
			printf("%c", c1);
			// 已经被输出了 
			HashTable[c1] = true;
		}
	}
	return 0;
}
