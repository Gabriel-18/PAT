#include <bits/stdc++.h>

using namespace std;
vector<int> in;
vector<int> pre;
unordered_map<int, int> mp;


void build(int inL, int inR, int preRoot, int a, int b) {
    if (inL > inR) {
        return;
    }
    int rootVal = pre[preRoot];
    int inRoot = mp[rootVal];

    // ab在右边
    if (inRoot < mp[a] && inRoot < mp[b]) {
        build(inRoot + 1, inR, preRoot + inRoot - inL + 1, a, b);

        // ab在左边
    } else if (inRoot > mp[a] && inRoot > mp[b]) {
        build(inL, inRoot - 1, preRoot + 1, a, b);

    } else if ((inRoot > mp[a] && inRoot < mp[b]) || (inRoot < mp[a] && inRoot > mp[b])) {
        printf("LCA of %d and %d is %d.\n", a, b, rootVal);
    } else if (inRoot == mp[a]) {
        printf("%d is an ancestor of %d.\n", a, b);
    } else if (inRoot == mp[b]) {
        printf("%d is an ancestor of %d.\n", b, a);
    }
}

int main() {
    int n, m;
    cin >> m >> n;
    in.resize(n + 1);
    pre.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> in[i];
        mp[in[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        cin >> pre[i];
    }

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        if (mp[a] == 0 && mp[b] == 0) {
            printf("ERROR: %d and %d are not found.\n", a, b);
        } else if (mp[a] == 0 || mp[b] == 0) {
            printf("ERROR: %d is not found.\n", mp[a] == 0 ? a : b);
        } else {
            build(1, n, 1, a, b);
        }
    }
    return 0;
}