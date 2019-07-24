#include<cstdio>
const int maxn = 1001;
struct Student {
	long long id;
	int examSeat;
}testSeat[maxn];
int main() {
	int n, m;
	long long id;
	int examSeat, seat;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%lld %d %d", &id, &seat, &examSeat);
		testSeat[seat].id = id;
		testSeat[seat].examSeat = examSeat;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		int seat;
		scanf("%d", &seat);
		printf("%lld %d\n", testSeat[seat].id, testSeat[seat].examSeat);
	}
	return 0;
} 
