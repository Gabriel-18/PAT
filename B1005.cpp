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
			hashTable[m] = true; // �����ǵ�����flag ��Ϊtrue 
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
		if (hashTable[a[i]] == false) { // �Ӵ�С û�б����ǵľ��� 
			printf("%d", a[i]);
			count--;
			if (count > 0) printf(" "); 
		}
	}
	return 0;
}
