//
// Created by kelper on 2020/8/25.
//
#include <bits/stdc++.h>
using namespace std;
unordered_set<int> set1;
unordered_set<int> set2;
bool judge(int num) {
    for (auto it = set1.begin(); it != set1.end(); ++it) {
        int a = *it;
        if (set1.find(a + num) != set1.end()) {
            return true;
        }
    }
    return false;
}
int main () {
    int a, b;
    cin >> a >> b;
    int n, m;
    cin >> n >> m;
    int num[12][110];

    set1.insert(a);
    set1.insert(b);
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> num[i][j];
        }
    }

    // 按列
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // 忽略已经被淘汰的
            if (set2.find(j) != set2.end()) {
                continue;
            }
            int x = num[j][i];
            // 重复 或者 不是差
            if (set1.find(x) != set1.end() || !judge(x)) {
                printf("Round #%d: %d is out.\n",i,j);
                // 统计失败者 不是失败的就是成功的
                set2.insert(j);
            } else {
                set1.insert(x);
            }
        }
    }
    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        if (set2.find(i) == set2.end()) {
            if (flag == false) {
                flag = true;
                printf("Winner(s): %d",i);
            } else {
                printf(" %d", i);
            }
        }
    }

    // 没有winner
    if (flag == false) {
        printf("No winner.");
    }



    return 0;
}
