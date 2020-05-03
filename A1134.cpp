//
// Created by kelper on 2020/5/3.
//

#include <iostream>
#include <vector>
using namespace std;
// 给点构图
// 用点集S查询 是否与所有边有关系
// 必须建立点和边的关系
//    v[a].push_back(i);
//    v[b].push_back(i);

// 扫描某个点的边集合
// 进行标记
// 如果所有的边被标记了 则符合题目要求
int main() {
    int n, m, k;
    scanf("%d %d",&n, &m);

    // 点集
    vector<int > v[n];
    // 用点描述边
    int a, b;
    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        v[a].push_back(i);
        v[b].push_back(i);
    }

    int nv, num;
    // 做查询
    scanf("%d", &k);
    for (int j = 0; j < k; ++j) {
        scanf("%d", &nv);
        int flag = 0;
        vector<int> hash(m, 0);

        for (int i = 0; i < nv; ++i) {
            scanf("%d", &num);
            // 遍历与该点相关的边 标记
            for (int l = 0; l < v[num].size(); ++l) {
                hash[v[num][l]] = 1;
            }
        }

        //  判断 是不是所有的边都有关系
        for (int j = 0; j < m; ++j) {
            if (hash[j] == 0) {
                printf("No\n");
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            printf("Yes\n");
        }
    }
    return 0;
}