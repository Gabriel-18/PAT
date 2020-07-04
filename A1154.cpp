#include <bits/stdc++.h>

using namespace std;
// 点描述边
struct node {
    int a, b;
};

int main() {
    int n, m;
    cin >> n >> m;

    // 怎么用点描述
    // 边呢 用索引充当边
    // 边与点与点关系
    // 就是一个类似的map 题目给的很特别 直接就能做了
    vector<node> v(m);
    for (int i = 0; i < m; ++i) {
        cin >> v[i].a >> v[i].b;
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        // 点对应的颜色
        vector<int> c(n);
        set<int> set;
        int flag = 0;
        // 初始化点对应的集合
        for (int j = 0; j < n; ++j) {
            cin >> c[j];
            set.insert(c[j]);
        }

        // 开始扫边
        for (int l = 0; l < m; ++l) {
            // 有一样颜色的
            if (c[v[l].a] == c[v[l].b]) {
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            printf("No\n");
        } else {
            printf("%d-coloring\n", set.size());
        }
    }
    return 0;
}