//
// Created by kelper on 2020/2/14.
//

#include <iostream>
#include <vector>
using namespace std;
int m, n;
vector<int> v;
int isMin = 1, isMax = 1;
void postOrder(int index) {
    if (index >= n) {
        return;
    }

    postOrder(index * 2 + 1);
    postOrder(index * 2 + 2);
    printf("%d%s", v[index],  " ");
}
int main() {
    cin >> m >> n;
    v.resize(n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[j];
        }
        int flag = v[0] > v[1] ? 1 : -1;
        for (int j = 0; j < n  / 2; ++j) {
            int left = 2 * j + 1, right = 2 * j + 2;
            if (flag == 1 && (v[j] < v[left] || (right < n && v[j] < v[right]))) {
                flag = 0;
            }
            if (flag == -1 && (v[j] > v[left] || (right < n && v[j] > v[right]))) {
                flag = 0;
            }
        }
        if (flag == 0) {
            printf("Not Heap\n");
        } else {
            printf("%s Heap\n", flag == 1 ? "Max" : "Min");
        }
        postOrder(0);
    }
    return 0;
}