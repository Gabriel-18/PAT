#include <bits/stdc++.h>

using namespace std;
bool isPrime(int n) {
    if (n == 0 || n == 1) {
        return false;
    }

    // 带不带等号都没影响
    for (int i = 2; i * i <= n; ++i) {
        // 有除1和自己本身外的余数
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int l, k;
    cin >> l >> k;
    string s;
    cin >> s;


    // 打个草稿就知道了
    for (int i = 0; i <= l - k; ++i) {
        string a = s.substr(i, k);
//        cout << a << endl


        int num = stoi(a);
        if (isPrime(num)) {

            cout << a;
            return 0;
        }
    }
    cout << 404;
    return 0;
}