#include<cstdio>
const int Galleon = 17 * 29;
const int Sickle = 29; 
int main() {
	// 存在可能中间计算范围超过int的情况 int 大概10^9  
	long long  a1, b1, c1, a2, b2, c2;
	scanf("%lld.%lld.%lld %lld.%lld.%lld", &a1, &b1, &c1, &a2, &b2, &c2);
	long long sum = a1 * Galleon + b1 * Sickle + c1 + a2 * Galleon + b2 * Sickle + c2;
	printf("%lld.%lld.%lld", sum / Galleon, sum % Galleon / Sickle, sum % Sickle);
}
