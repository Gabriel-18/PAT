// 模拟 
#include<cstdio>
#include<stack>
using namespace std;
const int maxn = 1010;
int arr[maxn];
stack<int> st;
int main() {
	int m,n,t;
	scanf("%d%d%d", &m, &n, &t);
	while(t--) {
		while(!st.empty()) {
			st.pop();
		}
		for (int i = 1; i <= n; i++) { //读入数据 
			scanf("%d", &arr[i]); 
		}
		int current = 1; // 指向栈序列中的待出栈元素 
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			st.push(i); // 入栈 
			if (st.size() > m) { // 如果此时栈中元素个数超过m 
				flag = false;
				break;
			}
			// 栈顶和出当前位置的栈序列元素一致时 
			while (!st.empty() && st.top() == arr[current]) {
				st.pop();
				current++;
			}
		}
		if (st.empty() == true && flag == true) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
} 
