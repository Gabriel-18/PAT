#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
    // 判断素数需要考虑0 1
    if (n == 0 || n == 1) {
        return false;
    }
// 快速解法
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
// 坑在大数
int main() {
    int l, k;
//    scanf("%d %d", &l, &k);
    cin >> l >> k;
    string s;
    cin >> s;
    // 范围通过实例得出
    // 0 7 5
    // 最后一组数据 2  7
    for (int i = 0; i <= l - k; i++) {
        // 截取从i开始的 k个字符
        string t = s.substr(i,k);
        // string to int
        int num = stoi(t);
        if (isPrime(num)) {
            // 直接输出字符串 防止大数溢出
            cout << s;
            return 0;
        }
    }
    printf("404");
    return 0;
}