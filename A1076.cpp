//
// Created by kelper on 2019/12/13.
//

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int MAXV = 1010;
struct Node {
    int id;
    int layer;
};
vector<Node> Adj[MAXV];
bool inq[MAXV] = {false};

int BFS(int s, int L) {
    int numForward = 0;
    queue<Node> q;
    Node start;
    start.id = s;
    start.layer = 0;
    q.push(start);
    inq[start.id] = true;
    while (!q.empty()) {
        Node topNode = q.front();
        q.pop();
        int u = topNode.id;
        for (int i = 0; i < Adj[u].size(); ++i) {
            Node next = Adj[u][i];
            next.layer = topNode.layer + 1;
            if (inq[next.id] == false && next.layer <= L) {
                q.push(next);
                inq[next.id] = true;
                numForward++;
            }
        }
    }
    return numForward;
}

int main() {
    Node user;
    int n, L, numFollow, idFollow;
    scanf("%d%d", &n, &L);
    // 题目要求 1 - N
    for (int i = 1; i <= n; ++i) {
        user.id = i;
        scanf("%d", &numFollow);

        for (int j = 0; j < numFollow; ++j) {
            scanf("%d", &idFollow);
            Adj[idFollow].push_back(user);
        }
    }
    int numQuery, s;
    scanf("%d", &numQuery);
    for (int i = 0; i < numQuery; ++i) {
        // 每做一次初始化一次
        memset(inq, false, sizeof(inq));
        scanf("%d", &s);
        int numForward = BFS(s, L);
        printf("%d\n", numForward);
    }
    return 0;
}