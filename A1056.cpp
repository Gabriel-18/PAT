//
// Created by Kelper on 2019/10/31.
//

#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1010;

struct mouse {
    int weight;
    int r;
}mouse[maxn];

int main() {
    int np, ng, order;
    scanf("%d%d", &np, &ng);
    for (int i = 0; i < np; ++i) {
        scanf("%d", &mouse[i].weight);
    }
    queue<int> q;
    for (int i= 0; i < np; ++i) {
        scanf("%d", &order);
        q.push(order);
    }

    int temp = np, group;
    while (q.size() != 1) {
        // 计算比赛轮数
        if (temp % ng == 0) {
            group = temp / ng;
        } else {
            group = temp / ng + 1;
        }

        // 枚举一组 选出该组最大
        for (int i = 0; i < group; ++i) {
            int k = q.front();
            for (int j = 0; j < ng; ++j) {
                // 理论上是不可能的
                // 一旦达到这个情况 即是说明超了
                if (i * ng + j >= temp) {
                    break;
                }

                int front = q.front();
                if (mouse[front].weight > mouse[k].weight) {
                    k = front; // 找出最大值
                }

                mouse[front].r = group + 1;
                q.pop();
            }
            q.push(k);
        }
        temp = group;// group只晋级
    }
    mouse[q.front()].r = 1;
    for (int i = 0; i < np; ++i) {
        printf("%d", mouse[i].r);
        if (i < np - 1) {
            printf(" ");
        }
    }
    return 0;
}