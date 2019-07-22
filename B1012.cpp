#include<cstdio>
int main() {
	int n, m;
	int count[5] = {0};
	int ans[5] = {0};
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		
		scanf("%d", &m);
		
		if(m % 5 == 0 && m % 2 == 0) {
			ans[0] += m;
			count[0]++; 
		} else if(m % 5 == 1) {
			if(count[1] % 2 == 0) {
				ans[1] += m;
			} else {
				ans[1] -= m;
			}
			count[1]++;
		} else if(m % 5 == 2) {
			count[2]++;
			ans[2] = count[2];
		} else if(m % 5 == 3) {
			ans[3] += m;
			count[3]++;
		} else if(m % 5 == 4) {
			if(m > ans[4]) {
				ans[4] = m;
			}
			count[4]++;
		}
	} 
	
	

		if(count[0] == 0) printf("N ");
		else printf("%d ",ans[0]);
		if(count[1] == 0) printf("N ");
		else printf("%d ",ans[1]);
		if(count[2] == 0) printf("N ");
		else printf("%d ",ans[2]);
		if(count[3] == 0) printf("N ");
		else printf("%.1f ",(double)ans[3] / count[3]);
		if(count[4] == 0) printf("N") ;
		else printf("%d",ans[4]);
	
	return 0;
} 
