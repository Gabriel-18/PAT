//
// Created by kelper on 2020/3/29.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int > pre, in;
bool flag = false;
// 前中求后
void postOrder(int preL, int inL, int inR) {
    if (inL > inR || flag == true) {
        return;
    }

    int i = inL;
    // 找到分界线 也就是根
    while (in[i] != pre[preL]) {
        i++;
    }
    // 左边界
    postOrder(preL + 1, inL, i - 1);
    // 右边界
    postOrder(preL + 1 + i - inL, i + 1, inR);
    if (flag == false) {
        printf("%d", in[i]);
        flag = true;
    }
}

int main() {
    int n;
    cin >> n;
    pre.resize(n);
    in.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> pre[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> in[i];
    }

    postOrder(0, 0, n - 1);
    return 0;
}