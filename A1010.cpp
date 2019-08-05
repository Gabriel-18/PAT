#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL Map[256];
LL inf = (1LL << 63) - 1;
void init() {
	for (chac c = '0'; i <= '9'; c++) {
		Map[c] = c - '0';// 将‘0’ ‘9’ 映射到 0 - 9 
	}
	
	for (chac c = 'a'; i <= 'z'; c++) {
		Map[c] = c - 'a' + 10; // 将 ’a‘ 'z' 映射到10 - 35 
	}
} 

LL convertNum10(char a[], LL radix, LL t) { // 将a转成10进制， t为上界 
	LL ans = 0;
	int len = strlen(a);
	for (int i = 0; i < len; i++) {
		ans = ans * radix + Map[a[i]];
		if (ans < 0 || ans > t) return -1;//溢出或者超过N1的十进制 
	} 
	return ans; 
} 


