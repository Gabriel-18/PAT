#include<bits/stdc++.h>
using namespace std;
struct node {
    int address, data, next;
}a[1000005];

// 主要是装入的问题
// 画图
int main() {
    int begin, n, k;
    cin >> begin >> n >> k;
    vector<node> v, ans;
    int start, data, next;
    
    // 读数据
    for (int i = 0; i < n; ++i) {
        cin >> start >> data >> next;
        a[start] = {start, data, next}; 
    }

    // 将链表装入数组
    for (; begin != -1; begin = a[begin].next) {
        v.push_back(a[begin]);
    }

    int len = v.size(), j = 0;
    // 计算不足一个block的数量
    int remain = len % k;
    int group = 0;
    ans.resize(len);
    // 遍历数组
    for (int i = 0; i < len; ++i) {
        // 前面那几个完整的block
        // 1 - len / k group
        if (i < len - remain) {
            // 0 - len / k
            group = len / k - i / k - 1;
            int index = k * group + j + remain;
            ans[index] = v[i];
            // 组内偏离
            j = (j + 1) % k;
        } else {
            // 直接映射到 0号组
            ans[i % k] = v[i];
        }
    }

    for (int i = 0; i < len; ++i) {
        if (i != ans.size() - 1) {
            printf("%05d %d %05d\n", ans[i].address, ans[i].data, ans[i + 1].address);
        } else {
            printf("%05d %d -1\n",ans[i].address,ans[i].data);
        }
    }
    
    return 0;
}