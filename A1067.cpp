#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int pos[maxn];  // ��Ÿ����ֵ�ǰ���ڵ�λ�ñ�� 
int main() {
	int n, ans = 0; // ans ��ʾ�ܽ������� 
	scanf("%d", &n); 
	int left = n - 1, num; // left��ų�0���ⲻ�ڱ�λ�����ĸ���
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		pos[num] = i; // num[i] ����λ��Ϊ i
		
		if (num == i && num != 0) { // �����0�����б�λ�ϵ���
			left--;	
		} 
	} 
	// ��������  
	int k = 1; // k ��ų�0���ⲻ�ڱ�λ�ϵ���С����
	while (left > 0) {
		// ���0�ڱ�λ ��Ѱ��һ����ǰ���ڱ�λ�ϵ�����0����
		// ö�� 
		if (pos[0] == 0) {
			while (k < n) {
				if (pos[k] != k) {
					swap(pos[0], pos[k]);
					ans++;
					break;
				}
				k++;
			}
		} 
		
		// ֻҪ0���ڱ�λ �ͽ�0����λ�õ����ĵ�ǰ����λ����0��λ�ý��� 
		while (pos[0] != 0) {
			//  pos[pos[0]]Ϊ0 �������� 
			swap(pos[0], pos[pos[0]]);  //��0��pos[0]���� 
			ans++;//����������һ 
			left--; //���ڱ�λ�����ĸ�λ��һ 
		}
	
	} 
	

	printf("%d", ans); 
	return 0;
} 
