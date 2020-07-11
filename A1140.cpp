#include <bits/stdc++.h>

using namespace std;

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
            s += d[j] + to_string(count);
//            s += d[j] + count;
        }
        d = s;
    }
    cout << d;
    return 0;
}