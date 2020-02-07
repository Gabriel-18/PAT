//
// Created by kelper on 2020/2/7.
//
#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int > v;
int a[1009], n, isMin = 1, isMax = 1;
//：1.深搜打印出所有路路径（从右往左，即先序的镜像），
// vector保存⼀一路路上的节点，通过push和 pop回溯，维护路路径
void dfs(int index) {
    // 左右子节点没了
    if (index * 2 > n && index * 2 + 1 > n) {
//        index <= n是对只有左叶节点没有右叶节点的点特判
        if (index <= n) {
            for (int i = 0; i < v.size(); ++i) {
                printf("%d%s",v[i], i != v.size() - 1 ? " " : "\n");
            }
        }

        return;
    } else {
        // 往右走
        v.push_back(a[index * 2 + 1]);
        dfs(index * 2 + 1);
        v.pop_back();
// 8
//98 72 86 60 65 12 23 50
        // 往左走
        v.push_back(a[index * 2]);
        dfs(index * 2);
        v.pop_back();
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    v.push_back(a[1]);
    dfs(1);
    for (int i = 2; i <= n; ++i) {
        if (a[i / 2] > a[i]) {
            isMin = 0;
        }

        if (a[i / 2] < a[i]) {
            isMax = 0;
        }
    }

    if (isMin == 1) {
        printf("Min Heap");
    } else {
        printf("%s", isMax == 1 ? "Max Heap" : "Not Heap");
    }
    return 0;
}