#include<cstdio>
int main() {
	char str[90][90];
	int num = 0;
	// ����Ϊɶ������str����num++ �ᵼ�±�ʵ�ʵĳ��ȴ�һ Ȼ���ƻ������ 
	while(scanf("%s", str[num]) != EOF) {
		num++;
	}
	for(int i = num - 1; i >= 0; i--) {
		printf("%s", str[i]);
		if(i != 0) printf(" ");
	}
	return 0;
} 
