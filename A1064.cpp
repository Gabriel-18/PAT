//
// Created by kelper on 2019/12/11.
//
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int n, number[maxn], CBT[maxn], index = 0;

void inOrder(int root) {
    if (root > n) {
        return;
    }
    inOrder( root * 2) ;
    CBT[root] = number[index++];
    inOrder(root * 2 + 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &number[i]);
    }
    sort(number, number + n);
    inOrder(1);
    for (int j = 1; j <= n; ++j) {
        printf("%d", CBT[j]);
        if (j < n) {
            printf(" ");
        }
    }
    return 0;
}
