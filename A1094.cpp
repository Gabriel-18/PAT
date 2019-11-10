//
// Created by Kelper on 2019/11/10.
//
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 110;
vector<int> Node[MAXN];
int hashTable[MAXN] = {0};

void DFS(int index, int level) {
    hashTable[level]++;
    for (int i = 0; i < Node[index].size(); ++i) {
        DFS(Node[index][i], level + 1); // 遍历所有孩子节点
    }
}

int main() {

    int n, m, parent, k, child;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &parent, &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &child); // 孩子节点的编号
            Node[parent].push_back(child); // 建树
        }
    }
    DFS(1, 1); // 根节点为1号 层号为1
    int maxLevel = -1, maxValue = 0;
    for (int i = 0; i < MAXN; ++i) {
        if (hashTable[i] > maxValue) {
            maxValue = hashTable[i];
            maxLevel = i;
        }
    }
    printf("%d %d\n", maxValue, maxLevel);
    return  0;
}