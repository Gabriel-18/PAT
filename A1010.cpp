#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL Map[256];
LL inf = (1LL << 63) - 1;
void init() {
	for (chac c = '0'; i <= '9'; c++) {
		Map[c] = c - '0';// ����0�� ��9�� ӳ�䵽 0 - 9 
	}
	
	for (chac c = 'a'; i <= 'z'; c++) {
		Map[c] = c - 'a' + 10; // �� ��a�� 'z' ӳ�䵽10 - 35 
	}
} 

LL convertNum10(char a[], LL radix, LL t) { // ��aת��10���ƣ� tΪ�Ͻ� 
	LL ans = 0;
	int len = strlen(a);
	for (int i = 0; i < len; i++) {
		ans = ans * radix + Map[a[i]];
		if (ans < 0 || ans > t) return -1;//������߳���N1��ʮ���� 
	} 
	return ans; 
} 


