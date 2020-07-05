#include <bits/stdc++.h>

using namespace std;
vector<int> v;
vector<int> path;
int n;
void dfs(int index) {

    if (2 * index > n && 2 * index + 1 > n) {
//        if (index <= n) {
            for (int i = 0; i < path.size(); ++i) {
                printf("%d%s",path[i],i + 1 == path.size() ? "\n":" ");
            }
//        }
//        return;
    } else {
        // 先右
        if (index * 2 + 1 < n) {
            path.push_back(v[index * 2 + 1]);
            dfs(index * 2 + 1);
            path.pop_back();
        }


        path.push_back(v[index * 2]);
        dfs(index * 2);
        path.pop_back();
    }



}
int main() {

    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    int isMax = 0, isMin = 0;
    for (int i = 2; i <= n; ++i) {
        if (v[i] >= v[i / 2]) {
            isMin = 1;
        }

        if (v[i] <= v[i / 2]) {
            isMax = 1;
        }
    }
    path.push_back(v[1]);

    dfs(1);
    // 判断什么堆 点送
    if (isMax == 1 && isMin == 1) {
        printf("Not Heap");
    } else if (isMax == 1) {
        printf("Max Heap");
    } else {
        printf("Min Heap");
    }
    return 0;
}