#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m;
    unordered_map<int,vector<int>> mp;
    int a,  b;
    for (int i = 1; i <= m; ++i) {

//        cin >> a >> b;
        scanf("%d %d",&a,&b);
        mp[a].push_back(i);
        mp[b].push_back(i);
    }
    cin >> k;
    int num;
    int nv;
    for (int i = 0; i < k; ++i) {

//        cin >> nv;
        scanf("%d",&nv);
        int flag = 0;
        vector<int> hash(m + 1, 0);
        for (int j = 0; j < nv; ++j) {

//            cin >> num;
            scanf("%d",&num);
            // 扫边
            for ( int a : mp[num] ) {
                hash[a] = 1;
            }
        }

        for (int j = 1; j <= m; ++j) {
            if (hash[j] == 0) {
                printf("No\n");
                flag = 1;
                break;
            }
        }
        if (flag == 0) printf("Yes\n");
    }
    return 0;
}