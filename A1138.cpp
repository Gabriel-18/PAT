#include <bits/stdc++.h>

using namespace std;
// 存前序
vector<int> v;
// 存中序 需要快速定位
unordered_map<int, int> mp;
bool flag = false;
void post(int inL,int inR, int preL){
    // 退出条件
    if (inL > inR || flag == true) {
        return;
    }

    int rootIndex = mp[v[preL]];
    // 向左
    post(inL, rootIndex - 1, preL + 1);
    // 向右
    post(rootIndex + 1, inR, preL + rootIndex - inL + 1);
    // 第一次输出
    if (flag == false) {
        printf("%d",v[preL]);
        flag = true;
    }

}
int main() {
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        mp[a] = i;
    }
    post(0,n-1,0);

    return 0;
}