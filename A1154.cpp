//
// Created by kelper on 2020/2/6.
//


#include <iostream>
#include <vector>
#include <set>
using namespace std;
// 用点描述边
struct node {
    int t1, t2;
};

int main() {
    int n, m, k;
    string s;
    cin >> n >> m;
    vector<node> v(m);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &v[i].t1, &v[i].t2);
    }

    cin >> k;
    while (k--) {
        // 颜色
        int a[10008] = {0};
        bool flag = true;
        set<int> se;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            se.insert(a[i]);
        }
        for (int i = 0; i < m; ++i) {
            if (a[v[i].t1] == a[v[i].t2]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            printf("%d-coloring\n", se.size());
        } else {
            printf("No\n");
        }
    }

    return 0;
}