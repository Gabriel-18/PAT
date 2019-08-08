#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int a[maxn];
void twoPointer(int n, int m) {
	int i = 0, j = n - 1;
	while (i < j) {
		if (a[i] + a[j] == m) break;
		else if (a[i] + a[j] < m) i++;
		else j++;
	}
	if (i < j) printf("%d %d", a[i], a[j]);
	else printf(" No Solution");
}

int main() {
	int n, m;
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	// ±ØÐëÏÈÅÅÐò 
	sort(a, a + n);
	twoPointer(n,m);
	return 0;
}
