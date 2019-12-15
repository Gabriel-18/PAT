//
// Created by kelper on 2019/12/13.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXV = 510;
const int INF = 1000000000;
/**
 * n 顶点数
 * m 变数
 * st 起点
 * ed 终点
 * d[] 最短距离
 * w[] 最大点权之和
 * num[] 最短路径条数
 */
int n, m, st, ed, G[MAXV][MAXV], weight[MAXV];
int d[MAXV], w[MAXV], num[MAXV];
bool vis[MAXV] = {false};

void Dijkstra(int s) {
    // 其他值
    fill(d, d + MAXV, INF);
    // 0 -1
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    for (int i = 0; i < n; ++i) {
        // u 使得d[u] 最小
        // MIN 存放最小的d[u] 初始放个大值
        int u = -1, MIN = INF;
        for (int j = 0; j < n; ++j) {
            // 没有被访问并且确实小
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        // 找不到小于INF的d{u} 说明剩下的顶点和起点不连通
        if (u == -1) {
            return;
        }

        // 标记u为已访问
        vis[u] = true;

        // 优化思路很容易
        for (int v = 0; v < n; ++v) {
            // 如果v未访问
            // 且u能到达v
            // 以u为中介点可以使d[v]更优
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    w[v] = w[u] + weight[v];
                    // 优化后 更新
                    num[v] = num[u];
                } else if (d[u] + G[u][v] == d[v]) {
                    // 以u为中介点时点权和更大
                    if (w[v] < w[u] + weight[v]) {
                        w[v] = w[u] + weight[v];
                    }
                    // 两个加起来
                    num[v] += num[u];
                }
            }
        }

    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &weight[i]);
    }
    int u, v;
    fill(G[0], G[0] + MAXV * MAXV, INF);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra(st);
    printf("%d %d\n", num[ed], w[ed]);
    return 0;
}