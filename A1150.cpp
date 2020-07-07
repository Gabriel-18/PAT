#include <bits/stdc++.h>

using namespace std;
int e[202][202];
int main() {
    int n, m;
    cin >> n >> m;
    int a, b, v;
    for (int i = 0; i < m; ++i) {
       cin >> a >> b >> v;
       e[a][b] = e[b][a] = v;
    }

    int k;
    cin >> k;
    int n1;
    int dist = INT_MAX;
    int index = -1;
    for (int i = 1; i <= k; ++i) {
        cin >> n1;
        vector<int> path(n1);
        int sum = 0;
        set<int> set;
        for (int j = 0; j < n1; ++j) {
            cin >> path[j];
            set.insert(path[j]);
        }
        int flag = 0;
        for (int l = 0; l < n1 - 1; ++l) {
            // NA
            if (e[path[l]][path[l + 1]] == 0) {
                flag = 1;
                break;
            }
            sum += e[path[l]][path[l + 1]];
        }
        // NA
        if (flag == 1) {
            printf("Path %d: NA (Not a TS cycle)\n", i);
            // 没访问所有 或者 有不通的
        } else if (path[0] != path[n1 - 1] || set.size() != n) {
            printf("Path %d: %d (Not a TS cycle)\n", i, sum);
            // 多个点
        } else if (n1 > n + 1) {

            if (dist > sum) {
                dist = sum;
                index = i;
            }
            printf("Path %d: %d (TS cycle)\n", i, sum);
            // 恰好
        } else {
            if (dist > sum) {
                dist = sum;
                index = i;
            }
            printf("Path %d: %d (TS simple cycle)\n", i, sum);
        }

//        if (dist > sum && flag == 0 && set.size() == n && path[0] == path[n1 - 1] ) {
//            dist = sum;
//            index = i;
//        }
//        if (set.size() == n && path.size() == n + 1 && path[0] == path[n1 - 1] && flag == 0) {
//            printf("Path %d: %d (TS simple cycle)\n", i, sum);
//        } else if (set.size() == n && path[0] == path[n1 - 1] && flag == 0) {
//            printf("Path %d: %d (TS cycle)\n",i, sum);
//        } else if (flag == 1) {
//            printf("Path %d: NA (Not a TS cycle)\n",i);
//        } else {
//            printf("Path %d: %d (Not a TS cycle)\n", i, sum);
//        }
//    }
    }
        printf("Shortest Dist(%d) = %d", index, dist);
        return 0;

}