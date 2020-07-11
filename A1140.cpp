#include <bits/stdc++.h>

using namespace std;
// 双指针
int main() {
    int  n;
    string d;
    cin >> d >> n;
    int k;
    for (int i = 1; i < n; ++i) {
        string s;
        for (int j = 0; j < d.size() ; j = k) {
            int count = 0;
            for (k = j;  ; ++k) {
                if (d[j] != d[k]) {
                    break;
                }
                else count++;
            }
            // 注意类型转化
            s += d[j] + to_string(count);
//            s += d[j] + count;
        }
        d = s;
    }
    cout << d;
    return 0;
}