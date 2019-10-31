//
// Created by Kelper on 2019/10/31.
// 心态炸了
//

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;

struct Node {
    int address, data, next;
    int order;
}node[maxn];

bool cmp(Node a, Node b) {
    a.order < b.order; // 从小到大排序
}

int main() {
    // 初始化
    for (int i = 0; i < maxn; ++i) {
        node[i].order = maxn;
    }
    int begin, n, K, address;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }

    int p = begin, count = 0;
    while (p != -1) {
        // 节点在单链表中的序号
        node[p].order = count++;
        p = node[p].next;
    }
    sort(node, node + maxn, cmp);

    n = count;

    return 0;
}