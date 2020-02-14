//
// Created by kelper on 2020/2/13.
//

//分析：⽤用邻接表v存储这个有向图，并将每个节点的⼊入度保存在in数组中
//对每⼀一个要判断是否是拓扑序列
// 如果当前结点的⼊度不为0则表示不是拓拓扑序列列，
// 每次选中某个点后要将它所指向的 所有结点的入度-1，
// 后根据是否出现过⼊度不为0的点
// 决定是否要输出当前的编号i
// flag是⽤用来判断 之前是否输出过
// 现在是否要输出空格的～
// judge是⽤用来判断是否是拓拓扑序列列的
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, a, b, k, flag = 0, in[1010];
    vector<int> v[1010];
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        v[a].push_back(b);
        in[b]++;
    }

    cin >> k;

    for (int i = 0; i < k; ++i) {
        int judge = 1;
        // 保证一次遍历后 in 维持不变
        vector<int> tin(in, in + n + 1);
        for (int j = 0; j < n; ++j) {
            cin >> a;
            if (tin[a] != 0) {
                judge = 0;
            }

            for (int it : v[a]) {
                tin[it]--;
            }
        }
        if (judge == 1) {
            continue;
        }
        // flag == 0 时 首次
        printf("%s%d", flag == 1 ? " " : "", i);
        flag = 1;
    }
    return 0;
}