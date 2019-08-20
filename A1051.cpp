// ģ�� 
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
		for (int i = 1; i <= n; i++) { //�������� 
			scanf("%d", &arr[i]); 
		}
		int current = 1; // ָ��ջ�����еĴ���ջԪ�� 
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			st.push(i); // ��ջ 
			if (st.size() > m) { // �����ʱջ��Ԫ�ظ�������m 
				flag = false;
				break;
			}
			// ջ���ͳ���ǰλ�õ�ջ����Ԫ��һ��ʱ 
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
