//
// Created by kelper on 2019/12/15.
//
#include <cstdio>
#include <cstring>
/***
 * 集合S中存放已被访问的顶点
 *
 * 每次从未被访问的顶点中 选择与起点距离最短的一个顶点u访问 并且加入S
 *
 * 之后以u为中介点 优化起点s 所有能从u到达的顶点v之间的最短距离
 */
#include <algorithm>
using namespace std;
const int MAXV = 1000;
const int INF = 1000000000;
int n, G[MAXV][MAXV];
//s 到 v的最短距离
int d[MAXV];
// S集合
bool vis[MAXV] = {false};

void Dijkstra(int s) {
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for (int i = 0; i < n; ++i) {

        // 占位而已 不要想太多
        int u = -1, MIN = INF;

        // 这里是通过轮询的方法 获得u
        for (int j = 0; j < n; ++j) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }

        if (u == -1) return;


        vis[u] = true;

        for (int v = 0; v < n; ++v) {
            if (vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];
            }
        }

    }
}
