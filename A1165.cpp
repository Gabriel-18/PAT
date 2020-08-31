#include <bits/stdc++.h>

using namespace std;


struct node {
    int id, data, next;
} a[1000005];

int main() {
    int begin, n, k, s, d, e;
    cin >> begin >> n >> k;
    vector<node> v, ans;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d\n", &s, &d, &e);
        a[s] = {s, d, e};
    }
    // 静态链表的遍历
    for (; begin != -1; begin = a[begin].next) {
        v.push_back(a[begin]);
    }
    int len = v.size(), j = 0;
    int m;
    // 多出来
    // 不足一个block的部分
    int remain = len % k;

    ans.resize(len);
    // 有点类似cache映射
    for (int i = 0; i < len; i++) {
        if (i < len - remain) {
            // 映射到哪个组
            m = len / k - i / k - 1;
            ans[k * m + j + remain] = v[i];
            j = (j + 1) % k;
        } else {
            // 不足1个block的那个组
            ans[i % k] = v[i];
        }
    }
    for (int i = 0; i < len; i++) {
        if (i != len - 1) {
            printf("%05d %d %05d\n", ans[i].id, ans[i].data, ans[i + 1].id);
        } else {
            printf("%05d %d -1", ans[i].id, ans[i].data);
        }
    }
    return 0;
}