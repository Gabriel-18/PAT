//
// Created by Kelper on 2019/11/7.
//

#include <cstdio>
#include <vector>
#include <algorithm>
using  namespace std;
const int maxn = 100010;
vector<int> child[maxn];
double p, r;
int n, maxDepth = 0, num = 0;

void DFS(int index, int depth) {
    if (child[index].size() == 0) {
        if (depth > maxDepth) {
            maxDepth = depth;
            num = 1;
        } else if (depth == maxDepth) {
            num++;
        }
        return;
    }
    for (int i = 0; i < child[index].size(); ++i) {
        DFS(child[index][i], depth + 1);// 递归访问节点index的子节点
    }
}

int main() {
    int father, root;
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &father);
        if (father != -1) {
            child[father].push_back(i); // i 是 father的子节点
        } else {
            root = i; // 根节点
        }
    }
    DFS(root, 0);
    printf("%.2f %d", p * pow(1 + r, maxDepth), num);
    return 0;
}