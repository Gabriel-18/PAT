#include<cstdio>
#include<cstring>
const int maxn = 100010;
bool hashTable[256];
char str[maxn];
int main() {
	memset(hashTable, true, sizeof(hashTable));
	// ��ȡʧЧ�ַ��� 
	fgets(str, maxn, stdin);
	int len = strlen(str);
	
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] - 'A' + 'a'; // ��дתСд 
		}
		hashTable[str[i]] = false; // ����ʧЧ 
	}
	
	// ��ȡ��������ַ���
	fgets(str, maxn, stdin);
	len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			int low = str[i] - 'A' + 'a'; // ��дתСд 
			if (hashTable[low] == true && hashTable['+'] == true) {
				printf("%c", str[i]); // ���Сд�ַ� 
			} 
		} else if (hashTable[str[i]] == true) {
				printf("%c", str[i]); // �����ַ� 
			}
		
	} 
	printf("\n");
	return 0;
}
