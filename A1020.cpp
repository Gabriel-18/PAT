//
// Created by Kelper on 2019/11/5.
//
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 50;
struct node {
    int data;
    node* lchild;
    node* rchild;
};
int pre[maxn], in[maxn], post[maxn];
int n; // 节点个数

node* create(int postL, int postR, int inL, int inR) {
    // 后序序列长度小于等于0 直接返回
    if (postL > postR) {
        return NULL;
    }
    // 存放根节点
    node* root = new node;
    // 新节点的数据域为根节点的值
    root->data = post[postR];
    int k;
    for (k = inL; k <= inR; ++k) {
        // 在中序序列中找到根节点
        if (in[k] == post[postR]) {
            break;
        }
    }
    // 左子树节点个数
    int numLeft = k - inL;
    root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
    root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
    return root;
}
int num = 0; // 已输出节点个数
void BFS(node* root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* now = q.front();
        q.pop();
        // 访问队首元素
        printf("%d", now->data);
        num++;
        if (num < n) { printf(" "); }
        if (now->lchild != NULL) {
            q.push(now->lchild);
        }
        if (now->rchild != NULL) {
            q.push(now->rchild);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &post[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }

    node *root = create(0, n - 1, 0, n - 1);
    BFS(root);
    return 0;
}