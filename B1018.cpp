#include<cstdio>
// ת��ʯͷ��������ϵ 
int change(char a) {
	if(a == 'B') return 0;
	if(a == 'C') return 1;
	if(a == 'J') return 2;
}
int main() {
	// �� ʯͷ ���� 
	char mp[3] = {'B','C','J'};
	int n;
	scanf("%d", &n);
	// ��¼����ʤƽ�� 
	int time_A[3] = {0}, time_B[3] = {0}; 
	// ��¼BCJ˳��ֱ��¼��������Ӯ�Ĵ���
	int hand_A[3] = {0}, hand_B[3] = {0};
	char c1, c2;
	int k1, k2;
	for(int i = 0; i < n; i++) {
		getchar();
		scanf("%c %c",&c1,&c2);
		 k1 = change(c1);
		k2 = change(c2);
		if((k1 + 1) % 3 == k2) {
			time_A[0]++;
			time_B[2]++;
			hand_A[k1]++;//�׿�k1ȡʤ 
		} else if (k1 == k2) {
			time_A[1]++;
			time_B[1]++;
		} else {
			time_A[2]++;
			time_B[0]++;
			hand_B[k2]++;//�ҿ�k2ȡʤ 
		}
	}
	printf("%d %d %d\n", time_A[0], time_A[1], time_A[2]);
	printf("%d %d %d\n", time_B[0], time_B[1], time_B[2]);
	int id1 =0, id2 = 0;
	for(int i = 0; i < 3; i++) {
		if(hand_A[i] > hand_A[id1]) id1 = i;
		if(hand_B[i] > hand_B[id2]) id2 = i;
	}
	printf("%c %c\n", mp[id1], mp[id2]);
	return 0;
}
