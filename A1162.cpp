//
// Created by kelper on 2020/9/4.
//

#include <bits/stdc++.h>

using namespace std;
struct node {
    string data;
    int l, r;
};
vector<node> v;
string dfs(int index) {
    // 左右都空
    if (v[index].l == -1 && v[index].r == -1) {
        return "(" + v[index].data + ")";
        // 左空 右不空 右继续搜索
        // 左不空 右空的情况 不存在
        // 结合图看会发现 结果不是一个算式
    } else if (v[index].l == -1 && v[index].r != -1) {
        return "(" + v[index].data + dfs(v[index].r) + ")";
    } else {
        // 左右都不空 都继续搜索
        return "(" + dfs(v[index].l) + dfs(v[index].r) + v[index].data+ ")";
    }
}
int main() {
    int n;
    cin >> n;
    v.resize(n + 1);
    unordered_map<int, int> map;
    // 给的当前节点的编号
    // 还有他的左右节点的编号
    // 用节点的编号可以直接访问左右节点
    for (int i = 1; i <= n; ++i) {
        cin >> v[i].data >> v[i].l >> v[i].r;
        // 标记出现过的节点号
        if (v[i].l != -1) {
            map[v[i].l] = 1;
        }

        if (v[i].r != -1) {
            map[v[i].r] = 1;
        }
    }

    // 没有出现过的节点号
    // 是root节点
    for (int i = 1; i <= n; ++i) {
        if (map[i] == 0) {
            cout << dfs(i);
            break;
        }
    }
    return 0;
}