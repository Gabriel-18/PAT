//
// Created by kelper on 2020/3/22.
//

#include <algorithm>
#include <cctype>
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct node {
    string school;
    int tws, ns;
};
//Then output the ranklist of institutions in nondecreasing order of their ranks in the following format: TWS
// The institutions are ranked according to their TWS. If there is a tie, the institutions are supposed to have the same rank,
// and they shall be printed in ascending order of Ns. If there is still a tie, they shall be printed in alphabetical order of their codes.
bool cmp(node a, node b) {
    // decreasing
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
    unordered_map<string, int> cnt;
    unordered_map<string, double> sum;
//    ID Score School
    for (int i = 0; i < n; ++i) {
        string id, school;
        double score;
        cin >> id;
        cin >> score;
//        scanf("%lf", &score);
        cin >> school;
//        all in lower case
        for (int j = 0; j < school.length(); ++j) {
            school[j] = tolower(school[j]);
        }
//        TWS is the total weighted score
//        which is defined to be the integer part of
//        ScoreB/1.5 + ScoreA + ScoreT*1.5
        if (id[0] == 'B') {
            score /= 1.5;
        } else if (id[0] == 'T') {
            score *= 1.5;
        }
        sum[school] += score;
        cnt[school] ++;
    }
    vector<node> ans;
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        ans.push_back(node{it->first,
                           (int)sum[it->first],
                           cnt[it->first]}
                           );
    }
    sort(ans.begin(), ans.end(), cmp);
    int rank = 0, pre = -1;
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        if (pre != ans[i].tws) {
            rank = i + 1;
        }
        pre = ans[i].tws;
        printf("%d ", rank);
        cout << ans[i].school;
        printf(" %d %d\n", ans[i].tws, ans[i].ns);
    }
    return 0;
}