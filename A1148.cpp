//
// Created by kelper on 2020/2/8.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// 就是个暴力题 别纠结
int main() {
    int n;
    cin >> n;
    // words
    vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            // a数组表示该
            // ⼈人是狼 人还是好人，
            // 等于1表示是好⼈
            // 等于-1表示是狼⼈
            vector<int> lie,a(n + 1, 1);
            // 如果两者都是狼人
            a[i] = a[j] = -1;

            for (int k = 1; k <= n; ++k) {
//                a [abs (v [k])] 的符号用v来判断当前假定条件下（a [i] 和 a [j] 是狼人），
//                v [k] 是当前第 k 个人说 v [k] 是村民还是狼人，符号来表示，
//                如果两者不一致，那么在此种假设下，就是说谎；
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