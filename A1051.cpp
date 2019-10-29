#include <cstdio>
#include <stack>
using namespace std;
const int maxn = 1010;
int arr[maxn];
stack<int> st;
// 感觉flag没啥屌用
int main() {
    int m, n, T;
    scanf("%d%d%d", &m, &n, &T);
    while (T--) {

        while (!st.empty()) {
            st.pop();
        }

        for (int i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
        }
        int current = 1;
        bool flag = true;
        // 模拟
        for (int i = 1; i <= n ; ++i) {
            st.push(i);
            if (st.size() > m) {
                flag = false;
                break;
            }
            // 栈顶元素与出栈序列当前位置元素相同时
            while (!st.empty() && st.top() == arr[current]) {
                st.pop();
                current++;
            }
        }
        // 结果判断
        if (st.empty() == true && flag == true) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}