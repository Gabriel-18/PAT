//
// Created by kelper on 2020/8/25.
//

#include <bits/stdc++.h>

using namespace std;
struct node {
    int a, b;
};
int main() {
    int n, r, k;
    cin >> n >> r >> k;
    vector<node> v(r + 1);

    // 构图
    for (int i = 1; i <= r; ++i) {
        cin >> v[i].a >> v[i].b;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        // 模拟放置
        vector<int> c(n + 1);
        set<int> set;
        int flag = 1;
        for (int j = 1; j <= n; ++j) {
            cin >> c[j];
            set.insert(c[j]);
        }

        // 特判条件必须写在前面
        if (k < set.size()) {
            printf("Error: Too many species.\n");
            continue;
        } else if (k > set.size()) {
            printf("Error: Too few species.\n");
            continue;
        }

        // 扫边
        for (int i = 1; i <= r; ++i) {
            if (c[v[i].a] == c[v[i].b]) {
                flag = 0;
                break;
            }
        }

        if (flag == 0) {
            printf("No\n");
        } else {
            if (k == set.size()) {
                printf("Yes\n");
            }
        }


    }
    return 0;
}