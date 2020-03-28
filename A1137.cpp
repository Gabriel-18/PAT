//
// Created by kelper on 2020/3/28.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
struct node {
    string name;
    int gp, gm, gf, g;
};
//The output must be sorted in descending order of their final grades (G must be rounded up to an integer).
// If there is a tie, output in ascending order of their StudentID's.
// It is guaranteed that the StudentID's are all distinct, and there is at least one qullified student.
bool cmp(node a, node b) {
    return a.g != b.g ? a.g > b.g : a.name < b.name;
}
map<string, int> idx;
//  the first line gives three positive integers: P , the number of students having done the online programming assignments;
//  M, the number of students on the mid-term list;
//  and N, the number of students on the final exam list.
//  All the numbers are no more than 10,000.
int main() {
    // 强转是截取尾部
//    cout << int(0.6);
    int p, m, f, score, cnt = 1;
    cin >> p >> m >> f;
    vector<node> v, ans;
    string s;
    // gp
    for (int i = 0; i < p; ++i) {
        cin >> s >> score;
        if (score >= 200) {
            v.push_back(node{s, score, -1, -1, 0});
            idx[s] = cnt++;
        }
    }

    // gm
    for (int i = 0; i < m; ++i) {
        cin >> s >> score;
        if (idx[s] != 0) {
            v[idx[s] - 1].gm = score;
        }
    }

    // gf
    for (int i = 0; i < f; ++i) {
        cin >> s >> score;
        if (idx[s] != 0) {
            int temp = idx[s] - 1;
            v[temp].gf = v[temp].g = score;
            if (v[temp].gm > v[temp].gf) {
                // 强转时会截去尾部
                v[temp].g = int(v[temp].gm * 0.4 + v[temp].gf * 0.6 + 0.5);
            }
        }
    }

    for (int i = 0; i < v.size(); ++i) {
        if (v[i].g >= 60) {
            ans.push_back(v[i]);
        }
    }

    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); ++i) {
        printf("%s %d %d %d %d\n", ans[i].name.c_str(), ans[i].gp, ans[i].gm,ans[i].gf, ans[i].g);
    }
    return 0;
}