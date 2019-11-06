//
// Created by Kelper on 2019/11/6.
//
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 110;
struct node {
    int lchild, rchild;
}Node[maxn];
// 记录是否为根节点 初始化均是
bool notRoot[maxn] = {false};
// n节点个数 num已输出个数
int n, num = 0;

void print(int id) {
    printf("%d", id);
    num++;
    if (num < n) {
        // 最后一个节点不输出空格
        printf(" ");
    } else {
        printf("\n");
    }
}
// 中序遍历
void inOrder(int root) {
    if (root == -1) {
        return;
    }
    inOrder(Node[root].lchild);
    print(root);
    inOrder(Node[root].rchild);
}
// 层序遍历
void BFS(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        print(now);
        if (Node[now].lchild != -1) {
            q.push(Node[now].lchild);
        }
        if (Node[now].rchild != -1) {
            q.push(Node[now].rchild);
        }
    }
}

// 后序遍历
void postOrder(int root) {
    if (root == -1) {
        return;
    }
    postOrder(Node[root].lchild);
    postOrder(Node[root].rchild);
    swap(Node[root].lchild, Node[root].rchild);
}

int strToNum(char c) {
    if (c == '-') {
        return -1; // 没用孩子节点
    } else {
        notRoot[c-'0'] = true; //标记c不是根节点
        return c - '0';// 返回节点编号
    }
}

// 寻找根节点
int findRoot() {
    for (int i = 0; i < n; ++i) {
        if (notRoot[i] == false) {
            return i; // 是根节点返回i
        }
    }
}
int main() {
    char lchild, rchild;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%*c%c %c", &lchild, &rchild);
        Node[i].lchild = strToNum(lchild);
        Node[i].rchild = strToNum(rchild);
    }
    int root = findRoot();
    // 交换
    postOrder(root);

    BFS(root);
    num = 0;
    inOrder(root);
    return 0;
}