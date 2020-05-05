//
// Created by kelper on 2020/5/5.
//
#include <iostream>
#include<vector>
using namespace std;
// 难点就是读清楚题目
int main() {
    int k;
    scanf("%d", &k);
    int n;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &n);
        vector<int> v(n);
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            scanf("%d", &v[j]);
            // 扫描前j - 1个元素
            for (int l = 0; l < j; ++l) {
                // 因为列不需要考虑
                // 只需要考虑列 和 对角线
                // 而且v[i]对应的是i-1列的某行元素
                // abs(v[l] - v[j]) == abs(l - j)
                // 同一对角线上满足的调剂 行列之差的绝对值相等
                if (v[l] == v[j] || abs(v[l] - v[j]) == abs(l - j)) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag == true) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
