#include <bits/stdc++.h>

using namespace std;
struct node {
    string school;
    int tws, ns;
};
string up(string s) {
    for (int i = 0; i < s.size(); ++i) {
        s[i] = tolower(s[i]);
    }
    return s;
}

bool cmp(node a, node b) {
    if (a.tws != b.tws) {
        return a.tws > b.tws;
    } else if (a.ns != b.ns) {
        return a.ns < b.ns;
    } else {
        return a.school < b.school;
    }
}
int main() {
    int n;
    cin >> n;
    map<string, int> count;
    map<string, double> tws;
    string id, school;
    double score;
    for (int i = 0; i < n; ++i) {
        cin >> id >> score >> school;
        school = up(school);
        count[school]++;
        if (id[0] == 'A') {
            tws[school] += score;
        } else if (id[0] == 'T') {
            tws[school] += 1.5 * score;
        } else if (id[0] == 'B') {
            tws[school] += score / 1.5;
        }
    }

    vector<node> ans;
    for (auto it : tws) {
        ans.push_back(node {
            it.first,
            (int)it.second,
            count[it.first]
        });

    }

    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n",ans.size());
    int rank = 0;
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i].tws != ans[rank].tws) {
            rank = i;
        }
        printf("%d %s %d %d\n",rank + 1, ans[i].school.c_str(), ans[i].tws, ans[i].ns);
    }

    return 0;
}