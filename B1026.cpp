#include<cstdio>
// ģ�� 
// �������� 
int main() {
	int c1, c2;
	scanf("%d%d",&c1, &c2);
	int ans = c2 - c1;
	
	//�������� 
	if(ans % 100 >= 50) {
		// ɵ��д��  ans /= 100 + 1
		ans = ans / 100 + 1;
	} else {
		ans /= 100;
	}
	//ans / 3600 ֱ�ӵõ�Сʱ��
	//ans % 3600 ��ȥСʱ��ʣ�µĲ��� 
	//ans % 60 ʣ�µ����� 
	printf("%02d:%02d:%02d", ans / 3600, ans % 3600 / 60 ,ans % 60);
	return 0;
}
