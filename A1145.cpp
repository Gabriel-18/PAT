#include <bits/stdc++.h>

using namespace std;
bool isPrime(int n) {
    if (n == 1 || n == 0) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int msize, n, m;
    cin >> msize >> n >> m;
    while (true) {
        if (isPrime(msize)) {
            break;
        }
        msize++;
    }
    vector<int> v(msize);
    int a;
    // 初始化 散列表
    // 插入数据
    for (int i = 0; i < n; ++i) {
        cin >> a;
        int flag = 0;
        for (int j = 0; j < msize; ++j) {
            // hash
            int pos = (a + j * j) % msize;
            if (v[pos] == 0) {
                v[pos] = a;
                flag = 1;
                // 插入成功
                // 不需要计算hash了
                break;
            }
        }
        // 无法解决冲突
        if (flag == 0) {
            printf("%d cannot be inserted.\n",a);
        }
    }

    int sum = 0;
    for (int i = 0; i < m; ++i) {
        cin >> a;
        for (int j = 0; j <= msize; ++j) {
            // hash
            int pos = (a + j * j) % msize;
            sum++;
            // 查找成功
            // 这里面根本没有就是没找到 直接退出
            if (v[pos] == 0 || v[pos] == a) {
                // 不需要计算hash了
                break;
            }
        }
    }
    printf("%.1lf", sum * 1.0 / m);
    return 0;
}