#include <bits/stdc++.h>

using namespace std;
struct node {
    string id;
    int score;
};
bool cmp(node a, node b){
    return a.score != b.score ? a.score > b.score : a.id < b.id;
}
int main() {
    int n, m;
    cin >> n >> m;
    string s;
    int score;
    // 用pushback 不要初始化
    vector<node> v;
    for (int i = 0; i < n; ++i) {
        cin >> s >> score;
        v.push_back(node{s, score});
    }

//    for (auto it : v) {
//        printf("%s %d \n", it.id.c_str(), it.score);
//    }

    int type;
    string term;
    for (int i = 1; i <= m; ++i) {
        cin >> type >> term;
        printf("Case %d: %d %s\n", i, type, term.c_str());
        vector<node> ans;
        int cnt = 0, sum = 0;
        if (type == 1) {
//            cout << "fuck" << endl;
            for (int j = 0; j < n; ++j) {
                if (v[j].id[0] == term[0]) {
                    ans.push_back(v[j]);
                }
            }
            sort(ans.begin(), ans.end(), cmp);
            for (auto it  : ans) {
                printf("%s %d\n", it.id.c_str(), it.score);
            }
            if (ans.size() == 0) {
                printf("NA\n");
            }

        } else if (type == 2) {
            for (int j = 0; j < n; ++j) {
                if (v[j].id.substr(1,3) == term) {
                    cnt ++;
                    sum += v[j].score;
                }
            }
            if (cnt != 0) {
                printf("%d %d\n", cnt, sum);
            } else if (cnt == 0) {
                printf("NA\n");
            }

        } else if (type == 3) {
            unordered_map<string, int> map;
            for (int j = 0; j < n; ++j) {
                if (v[j].id.substr(4,6) == term) {
                    map[v[j].id.substr(1,3)]++;
                }
            }

            for (auto it  : map) {
               ans.push_back(node{it.first, it.second});
            }

            sort(ans.begin(), ans.end(),cmp);

            for (auto it  : ans) {
                printf("%s %d\n", it.id.c_str(), it.score);
            }

            if (ans.size() == 0) {
                printf("NA\n");
            }
        }


    }
    return 0;
}