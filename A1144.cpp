#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> map;
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a > 0) map[a] = 1;
    }

//    for (int i = 1;; ++i) {
//        if (map[i] == 0) {
//            cout << i;
//            break;
//        }
//    }

    int num = 1;
    while (true) {
        if (map[num] == 0) {
            cout << num;
            break;
        }
        num++;
    }



    return 0;
}