#include <bits/stdc++.h>
using namespace std;
struct node {
    int address,
    data,
    next;
} a[100005];
int main() {
    int begin1, begin2, n;
    cin >> begin1 >> begin2 >> n;

    vector<node> va, vb, ans;
    int begin, data, next;
    for (int i = 0; i < n; ++i) {
        cin >> begin >> data >> next;
        a[begin] = {begin, data, next};
    }

    // 装入链表1
    for (;begin1 != - 1; begin1 = a[begin1].next) {
        va.push_back(a[begin1]);
    }

    // 装入链表2
    for (; begin2 != -1; begin2 = a[begin2].next) {
        vb.push_back(a[begin2]);
    }

    // b链表更短
    if (va.size() > vb.size()) {
        // 转b
        int j = (int) vb.size() - 1;
        // 遍历a链表
        for (int i = 0; i < va.size(); ++i) {
            // 装b链
            // 隔2次 装入
            // 从最后面 装入
            if (i > 0 && i % 2 == 0 && j >= 0) {
                ans.push_back(vb[j]);
                j--;
            }
            ans.push_back(va[i]);
            // 最后一次
            if (i == va.size() - 1 && j == 0) {
                ans.push_back(vb[j]);
            }
        }
    } else {
        int j = (int) va.size() - 1;
        for (int i = 0; i < vb.size(); ++i) {
            if (i > 0 && i % 2 == 0 && j >= 0) {
                ans.push_back(va[j]);
                j--;
            }
            ans.push_back(vb[i]);
            if (i == vb.size() - 1 && j == 0) {
                ans.push_back(va[i]);
            }
        }
    }


    for (int i = 0; i < ans.size(); ++i) {
        if (i != ans.size() - 1) {
            // 因为是按照顺序装入数组的
            // 直接输出下一个的地址即可
            printf("%05d %d %05d\n", ans[i].address, ans[i].data, ans[i + 1].address);
        } else {
            printf("%05d %d -1\n", ans[i].address, ans[i].data);
        }
    }
    return 0;
}