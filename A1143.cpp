//
// Created by kelper on 2020/3/24.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int, bool> mp;
//Each input file contains one test case.
// For each case, the first line gives two positive integers:
// M (≤ 1,000), the number of pairs of nodes to be tested; and N (≤ 10,000), the number of keys in the BST, respectively.
// In the second line, N distinct integers are given as the preorder traversal sequence of the BST.
// Then M lines follow, each contains a pair of integer keys U and V. All the keys are in the range of int.
int main() {
    int m, n;
    cin >> m >> n;
    vector<int> pre(n);
    for (int i = 0; i < n; ++i) {
        cin >> pre[i];
        mp[pre[i]] = true;
    }
    int u, v;
    int a;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        for (int j = 0; j < n; ++j) {
          a = pre[j];
            if ((a >= u && a <= v) || (a >= v && a <= u)) {
                break;
            }
        }
        if (mp[u] == false && mp[v] == false) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        } else if (mp[u] == false || mp[v] == false) {
            printf("ERROR: %d is not found.\n", mp[u] == false ? u : v);
        } else if (a == u || a == v) {
            printf("%d is an ancestor of %d.\n",a, a == u ? v : u);
        } else {
            printf("LCA of %d and %d is %d.\n",u,v,a);
        }
    }
    return 0;
}