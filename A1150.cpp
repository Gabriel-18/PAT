//
// Created by kelper on 2020/2/9.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;
// n 是顶点数
int e[202][202], n, m, k, ans = 999999999, ansid;
vector<int > v;

void check(int index) {
    int sum = 0, cnt, flag = 1;
    cin >> cnt;
    set<int> s;
    vector<int> v(cnt);
    for (int i = 0; i < cnt; ++i) {
        cin >> v[i];
        s.insert(v[i]);
    }

    for (int i = 0; i < cnt - 1; ++i) {
        // 相邻的两个顶点不可访问
        if (e[v[i]][v[i + 1]] == 0) {
            flag = 0;
        }
        sum += e[v[i]][v[i + 1]];
    }

    if (flag == 0) {
        printf("Path %d: NA (Not a TS cycle)\n", index);
        // 首尾不同 或者 没有访问过图中所有点
    } else if (v[0] != v[cnt - 1] || s.size() != n) {
        printf("Path %d: %d (Not a TS cycle)\n", index, sum);
        // 是否源点访问两次
    } else if (cnt != n + 1) {
        printf("Path %d: %d (TS cycle)\n", index, sum);
        if (sum < ans) {
            ans = sum;
            ansid = index;
        }
    } else {
        printf("Path %d: %d (TS simple cycle)\n", index, sum);
        if (sum < ans) {
            ans = sum;
            ansid = index;
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int t1, t2, t;
        cin >> t1 >> t2 >> t;
        e[t1][t2] = e[t2][t1] = t;
    }

    cin >> k;

    for (int i = 1; i <= k; ++i) {
        check(i);
    }
    printf("Shortest Dist(%d) = %d\n", ansid, ans);
    return 0;
}