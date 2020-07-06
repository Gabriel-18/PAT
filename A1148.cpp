#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    // 假设🐺
    // 然后谎言的个数为2
    // 狼一个 人一个
    for (int i = 1; i < n; ++i) {

        for (int j = i + 1; j <= n; ++j) {
            // 谎言
            vector<int> lie;
            // 表示狼和人
            vector<int> a(n + 1, 1);
            // 假定 i j 狼人
            a[i] = a[j] = -1;
            for (int k = 1; k <= n; ++k) {
                if (v[k] * a[abs(v[k])] < 0) {
                    lie.push_back(k);
                }
            }

            if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0) {
                cout << i << " " << j;
                return 0;
            }
        }
    }
    cout << "No Solution";
    return 0;
}