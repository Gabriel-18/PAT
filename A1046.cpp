#include<cstdio> 
#include<algorithm>
using namespace std;
const int MAXN = 100005;
//A[i]存放i号到i+1的距离
//dis[i]存放1到达i号的距离 
int dis[MAXN], A[MAXN];
int main() {
	printf("%d",dis[0]);
	int sum = 0, query, n, left, right;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		sum += A[i];
		dis[i] = sum;
	}
	
	scanf("%d", &query);
	for(int i = 0; i < query; i++) {
		scanf("%d%d", &left, &right);
		if(left > right) {
			swap(left, right);
		}
		int temp = dis[right - 1] - dis[left - 1];
		printf("%d\n",min(temp, sum - temp));
	}
	return 0;
}
