#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, m, a[110];
	scanf("%d", &n);
	bool hashTable[10000] = {0};
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		m = a[i];
		while (m != 1) {
			if (m % 2 == 1) m = (3 * m + 1) / 2;
			else m = m / 2;
			hashTable[m] = true; // 被覆盖的数的flag 置为true 
 		}
	}
	
	int count = 0; 
	for (int i = 0; i < n; i++) {
		if (hashTable[a[i]] == false) {
			count++;
		}
	}
	sort(a, a + n,cmp);
	
	for (int i = 0; i < n; i++) {
		if (hashTable[a[i]] == false) { // 从大到小 没有被覆盖的就是 
			printf("%d", a[i]);
			count--;
			if (count > 0) printf(" "); 
		}
	}
	return 0;
}
