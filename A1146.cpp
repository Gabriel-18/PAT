#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
//    vector<int> v[10002];

    cin >> n >> m;
    map<int, vector<int>> v;
    vector<int> in(n + 1);


    int a, b;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        v[a].push_back(b);
        // a - > b
        // b入度+1
        in[b]++;
    }

//    for (int i = 1; i <= n; ++i) {
//        printf("%d %d\n",i,in[i]);
//    }

    int k;
    cin >> k;
    int isPrint = 0;
    for (int i = 0; i < k; ++i) {
        vector<int> tin(n + 1);
        // 拷贝
        for (int j = 1; j <= n; ++j) {
            tin[j] = in[j];

        }

        int v1;
        int flag = 0;
        // 必须把数读完
        for (int j = 1; j <= n; ++j) {
            cin >> v1;
            // 入度为0 且 没有Kkk;

            // 判断条件写的复杂了
            // 判断不是 比这个容易 这个判断还容易写错
            // tin 和 in可能写混
//            if (tin[v1] == 0 && flag == 0) {
//                for (auto it : v[v1]) {
//                    // v1 指向的点
//                    // 入度减一
//                    tin[it]--;
//                }
//            } else {
//                flag = 1;
//            }

            // 入度如果不为0 不能被输出
            if (tin[v1] != 0) {
                flag = 1;
            } else {
                for (auto it : v[v1]) {
                    // v1 指向的点
                    // 入度减一
                    tin[it]--;
                }
            }
        }

//        if (flag == 1) {
//            if (isPrint == 0) {
//                isPrint = 1;
//                printf("%d",i);
//            }else {
//                printf( " %d", i);
//            }
//        }


        if (flag == 1) {
            printf("%s%d", isPrint == 0 ? "" : " ", i);
            isPrint = 1;
        }
    }

    return 0;
}