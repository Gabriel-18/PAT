//
// Created by Kelper on 2019/11/8.
//

#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;
const int maxn = 100010;
struct node {
    double data;
    vector<int > child;
} Node[maxn];
int n;
double p, r, ans = 0;

void DFS(int index, int depth) {
    if (Node[index].child.size() == 0) {
        ans += Node[index].data * pow(1 + r, depth);
        return;
    }
    for (int i = 0; i < Node[index].child.size(); ++i) {
        DFS(Node[index].child[i], depth + 1); // 递归访问子节点
    }
}
int main() {
    int k, child;
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        if (k == 0) {
            // 叶节点货物量
            scanf("%lf", &Node[i].data);
        } else {
            for (int j = 0; j < k; ++j) {
                scanf("%d", &child);
                Node[i].child.push_back(child); // child为节点i的子节点
            }
        }
    }
    DFS(0, 0);
    printf("%.1f\n", p * ans);
    return 0;
}