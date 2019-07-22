#include<cstdio>
// 模拟 
// 四舍五入 
int main() {
	int c1, c2;
	scanf("%d%d",&c1, &c2);
	int ans = c2 - c1;
	
	//四舍五入 
	if(ans % 100 >= 50) {
		// 傻逼写法  ans /= 100 + 1
		ans = ans / 100 + 1;
	} else {
		ans /= 100;
	}
	//ans / 3600 直接得到小时数
	//ans % 3600 除去小时数剩下的部分 
	//ans % 60 剩下的秒数 
	printf("%02d:%02d:%02d", ans / 3600, ans % 3600 / 60 ,ans % 60);
	return 0;
}
