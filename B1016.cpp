#include<cstdio>
/**
重点在于如何拆数
差不多就是用取余+除法这种方式
从低位到高位 
给的范围也大于了int 
**/
int main() {
	long long a, b, da, db;
	long long pa = 0, pb = 0;
	scanf("%lld%lld%lld%lld", &a, &da, &b, &db);
	while(a != 0) {
		if(a % 10 == da) pa = pa * 10 + da;
		a /= 10;
	}
	
	while(b != 0) {
		if(b % 10 == db) pb = pb * 10 + db;
		b /= 10;
	}
	
	printf("%lld", pa + pb);
	return 0;
} 
