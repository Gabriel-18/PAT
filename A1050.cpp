#include<cstdio>
#include<cstring>
const int maxn = 10010;
char a[maxn], b[maxn];
bool hashTable[150];
int main() {
	fgets(a, maxn, stdin);
	fgets(b, maxn, stdin);
	
	int len1 = strlen(a);
	int len2 = strlen(b);
	
	for (int i = 0; i < len2; i++) {
		hashTable[b[i]] = true; 
	}
	
	for (int i = 0; i < len1; i++) {
		if (hashTable[a[i]] == false) {
			printf("%c", a[i]);
		}
	}
	return 0;
}
