//
// Created by kelper on 2020/5/2.
//
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int id, data, next;
};

int main() {
    int begin, n, k;
    int adress, data, next;
    scanf("%d %d %d", &begin, &n, &k);
    node a[100010];
    vector<node> v, ans;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &adress, &data, &next);
        a[adress] = {adress, data, next};
    }

    // 组装链表
    while (begin != - 1) {
        v.push_back(a[begin]);
        begin = a[begin].next;
    }

    // 按段处理
    // 1.小于0
    for (int j = 0; j < v.size(); ++j) {
        if (v[j].data < 0) {
            ans.push_back(v[j]);
        }
    }
    // 2.大于等于0 小于等于k
    for (int l = 0; l < v.size(); ++l) {
        if (v[l].data >= 0 && v[l].data <= k) {
            ans.push_back(v[l]);
        }
    }
    //3.大于k
    for (int m = 0; m < v.size(); ++m) {
        if (v[m].data > k) {
            ans.push_back(v[m]);
        }
    }

    // 输出
    for (int i = 0; i < ans.size() - 1; ++i) {
        // 新的链表
        // 下一个就是ans[i+1].id
        printf("%05d %d %05d\n", ans[i].id, ans[i].data, ans[i + 1].id);
    }
    printf("%05d %d -1", ans[ans.size() - 1].id, ans[ans.size() - 1].data);
    return 0;
}
