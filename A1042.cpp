#include<cstdio>
const int N = 54;
//��źͻ�ɫ�Ĺ�ϵ 
char mp[5] = {'S','H', 'C', 'D', 'J'};
//next���ÿ��λ�õ����ڲ������λ�� 
int start[N+1], end[N+1], next[N+1];
int main() {
	int k;
	scanf("%d", &k);

		//init
	for(int i = 1; i <= N; i++) {
			start[i] = i;
	}
	for(int i = 1; i <= N; i++) {
			scanf("%d", &next[i]);
	}
		
	for(int i = 0; i < k; i++) {
		for(int j = 1; j <= N; j++) {
			end[next[j]] = start[j];
		}
		
	for(int j = 1; j <= N; j++) {
			start[j] = end[j];
		}
	}
	
	for(int i = 1; i <= N; i++) {
		if(i != 1) printf(" ");
		start[i] = start[i] - 1;
		printf("%c%d", mp[start[i] / 13], start[i] % 13 + 1);
	}
	return 0;
} 
