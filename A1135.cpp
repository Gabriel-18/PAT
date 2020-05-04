//
// Created by kelper on 2020/5/4.
//
//1. 根结点是否为黑色
//2. 如果一个结点是红色，它的孩子节点是否都为黑色
//3. 从任意结点到叶子结点的路径中，黑色结点的个数是否相同
//所以分为以下几步：
//0. 根据先序建立一棵树，用链表表示（常规的 DST 的建树方法）
//1. 判断根结点（题目所给先序的第一个点即根结点）是否是黑色
//2. 根据建立的树，从根结点开始遍历，如果当前结点是红色，判断它的孩子节点是否为黑色，递归返回结果
//3. 从根节点开始，递归遍历，检查每个结点的左子树的高度和右子树的高度（这里的高度指黑色结点的个数），比较左右孩子高度是否相等，递归返回结果
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct node {
    int val;
    struct node * left, * right;
};
vector<int> arr;
// 根据先序建树
node* build(node* root, int v) {
    if (root == NULL) {
        root = new node();
        root->val = v;
        root->left = root->right = NULL;
    } else if (abs(v) <= abs(root->val)) {
        root->left = build(root->left, v);
    } else {
        root->right = build(root->right, v);
    }
    return root;
}
// 父节点是红 则子都是黑
// 从根结点开始遍历，如果当前结点是红色，
// 判断它的孩子节点是否为黑色，递归返回结果
bool judge1(node* root){
    if (root == NULL) {
        return true;
    }

    // 父节点红
    // 两种情况下 不是
    if (root->val < 0) {
        if (root->left != NULL && root->left->val < 0) {
            return false;
        }

        if (root->right != NULL && root->right->val < 0) {
            return false;
        }
    }
    // 判断左右子树
    return judge1(root->left) && judge1(root->right);
}

//求出节点的高度（这里的高度指黑色结点的个数）
// 正数为黑
int getNum(node* root) {
    if (root == NULL) {
        return 0;
    }

    int l = getNum(root->left);
    int r = getNum(root->right);
    // 当节点为黑时 高度加一
    return root->val > 0 ? max(l, r) + 1 : max(l, r);
}

// 查每个结点的左子树的高度和右子树的高度（这里的高度指黑色结点的个数），
// 比较左右孩子高度是否相等，递归返回结果
bool judge2(node *root) {
    if (root == NULL) {
        return true;
    }
    int l = getNum(root->left);
    int r = getNum(root->right);
    if (l != r) {
        return false;
    }
    return judge2(root->left) && judge2(root->right);
}
int main() {
    int k, n;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &n);
        arr.resize(n);
        node* root = NULL;
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[j]);
            root = build(root, arr[j]);
        }

        if (arr[0] < 0 || judge1(root) == false || judge2(root) == false) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }

    return 0;
}
