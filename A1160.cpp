#include <bits/stdc++.h>

using namespace std;
// 求最大公约数
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
// 校验不小于3的素数
bool isPrime(int num) {
    // 小于3
    // 直接返回false
    if (num < 3) {
        return false;
    }
    // 素数判断模板
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
// 求整数的每一位数之和
int sum(int  n) {
    return n == 0 ? 0 : sum(n / 10) + n % 10;
}
struct node{
    int n, a;
};
// 按照给的数据写就行了
bool cmp(node &a, node &b) {
    if (a.n != b.n) {
        return a.n < b.n;
    } else {
        return a.a < b.a;
    }
}
int main() {
    int n;
    cin >> n;
    int k, m;
    int a, b;
    int c, d;
    for (int i = 1; i <= n; ++i) {
        cin >> k >> m;
        printf("Case %d\n", i);
        // 前k-2位 最多只有k - 3个0
        a = (int) pow(10, k - 3);
        // 越界的位置
        b = a * 10;
        vector<node> v;
        // 这个枚举怎么想的
        // 这个就很迷惑了
        // 末尾的99 已经定下来了
        // 能动的就只有 前k-2位
        for (int x = a; x < b; ++x) {
            c = x * 100 + 99;
            d = sum(c + 1);
            if (sum(c) == m && isPrime(gcd(d, m))) {
                v.push_back({d,c});
            }
        }

        if (v.size() == 0) printf("No Solution\n");
        else {
            sort(v.begin(), v.end(), cmp);
            for (auto it  : v ) {
                printf("%d %d\n", it.n, it.a);
            }
        }
    }


    return 0;
}