#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int>> map;
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    int k;
    for (int i = 0; i < m; ++i) {
        cin >> k;
        vector<int> v(k);
        unordered_map<int, int> f;
        for (int j = 0; j < k; ++j) {
            cin >> v[j];
            f[v[j]] = 1;
        }
        int flag = 0;

        for (int l = 0; l < k; ++l) {
            // 扫表肯定跑不掉
            for (auto it : map[v[l]]) {
                // 怎么判断这个东西是不是在这个集合里面
                // 空间换时间
                if (f[it] == 1) {
                    flag = 1;
                    break;
                }
            }
        }
        // 不能在判断后输出
        if (flag == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }

    }
    return 0;
}