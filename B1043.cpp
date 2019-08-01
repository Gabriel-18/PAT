#include<cstdio>
#include<cstring>
const int maxn = 10010;
char str[maxn], dict[6] = {'P', 'A', 'T', 'e', 's', 't'};
int hashTable[6] = {0}; //分别记录字符个数 
int main() {
	fgets(str, maxn, stdin);
	int len = strlen(str), sum = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 6; j++) { //// 遍历dict字典 
			hashTable[j]++;
			sum++; 
		} 
		 
	}
	while (sum > 0) {
		for (int i = 0; i < 6; i++) {
			if (hashTable[i] > 0) {
				printf("%c", dict[i]);
				hashTable[i]--;
				sum--;
			}
		}
	}
	return 0;
}
