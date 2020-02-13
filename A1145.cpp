//
// Created by kelper on 2020/2/13.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;
bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int tSize, n, m, a;
    cin >> tSize >> n >> m;
    while (!isPrime(tSize)) {
        tSize++;
    }

    vector<int> v(tSize);
    for (int i = 0; i < n; ++i) {
        cin >> a;
        int flag = 0;
        for (int j = 0; j < tSize; ++j) {
            // 开始探测
            int pos = (a + j * j) % tSize;
            if (v[pos] == 0) {
                v[pos] = a;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            printf("%d cannot be inserted.\n", a);
        }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        cin >> a;
        // 如果扫描完也找不到 则需要ans+1
        // 所以多算一次 所以这里取了等号
        for (int j = 0; j <= tSize; j++) {
            ans++;
            int pos = (a + j * j) % tSize;
            // 查到了 或 找不到
            if (v[pos] == a || v[pos] == 0) {
                break;
            }
        }


    }
    printf("%.1lf\n", ans * 1.0 / m);
    return 0;
}