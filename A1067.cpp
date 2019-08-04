#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int pos[maxn];  // 存放各数字当前所在的位置编号 
int main() {
	int n, ans = 0; // ans 表示总交换次数 
	scanf("%d", &n); 
	int left = n - 1, num; // left存放除0以外不在本位的数的个数
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		pos[num] = i; // num[i] 所处位置为 i
		
		if (num == i && num != 0) { // 如果除0以外有本位上的数
			left--;	
		} 
	} 
	// 交换策略  
	int k = 1; // k 存放除0以外不在本位上的最小的数
	while (left > 0) {
		// 如果0在本位 ，寻找一个当前不在本位上的数与0交换
		// 枚举 
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
		
		// 只要0不在本位 就将0所在位置的数的当前所在位置与0的位置交换 
		while (pos[0] != 0) {
			//  pos[pos[0]]为0 ？？？？ 
			swap(pos[0], pos[pos[0]]);  //将0与pos[0]交换 
			ans++;//交换次数加一 
			left--; //不在本位的数的个位减一 
		}
	
	} 
	

	printf("%d", ans); 
	return 0;
} 
