//
// Created by kelper on 2020/2/10.
//



#include <iostream>
#include <vector>
#include <map>
using namespace std;
// 中序 先序
vector<int> in, pre;
map<int, int> pos;
// 不需要建树
// 中序 左 根 右
// 前序 根 左 右
// lca 算法目标 找到两个点的最近祖先
// 祖先的特点是 在中序中位置 满足 左 < 根 < 右
void lca(int inl, int inr, int preRoot, int a, int b) {
    if (inl > inr) {
        return;
    }

    int inRoot = pos[pre[preRoot]], aIn = pos[a], bIn = pos[b];

    if (aIn < inRoot && bIn < inRoot) {
        // 跳到根的左子树区间
        // preRoot + 1 即可
        lca(inl, inRoot - 1, preRoot + 1, a, b);
    } else if ((aIn < inRoot && bIn > inRoot) || (aIn > inRoot && bIn < inRoot)) {
        printf("LCA of %d and %d is %d.\n", a, b, in[inRoot]);
    } else if (aIn > inRoot && bIn > inRoot) {
        // 同样需要到右子树区间
        // 先求出左子树区间大小 xx（inRoot - inl) + 1
        // preRoot + xx
        lca(inRoot + 1, inr, preRoot + 1 + (inRoot - inl), a, b);
    } else if (aIn == inRoot) {
        printf("%d is an ancestor of %d.\n", a, b);
    } else if (bIn == inRoot) {
        printf("%d is an ancestor of %d.\n", b, a);
    }
}
int main() {
//    printf("%d", pos[1000]);
    int m, n, a, b;
    cin >> m >> n;
    // Resizes the %vector to the specified number of elements.
    in.resize(n + 1), pre.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> in[i];
        pos[in[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> pre[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        // map里面没有存的东西 取出来为0
        if (pos[a] == 0 && pos[b] == 0) {
            printf("ERROR: %d and %d are not found.\n", a, b);
        } else if (pos[a] == 0 || pos[b] == 0) {
            printf("ERROR: %d is not found.\n", pos[a] == 0 ? a : b);
        } else {
            lca(1, n, 1, a, b);
        }
    }
    return 0;
}