#include <bits/stdc++.h>

using namespace std;
struct node {
    int val;
    struct node *left, *right;
};

vector<int> arr;
// 先序建二叉搜索树
node* build(node *root, int v) {
    if (root == NULL) {
        root = new node();
        root->val = v;
        root->right = root->left = NULL;
    } else if (abs(v) <= abs(root->val)) {
        root->left = build(root->left, v);
    } else {
        root->right = build(root->right, v);
    }
    return root;
}

bool judge1(node* root) {
    if (root == NULL) {
        return true;
    }
    // 根 红
    if (root->val < 0) {
        if (root->left != NULL && root->left->val < 0) {
            return false;
        }


        if (root->right != NULL && root->right->val < 0) {
            return false;
        }
    }
    // 搜子树
    return judge1(root->left) && judge1(root->right);
}
int getNum(node *root){
    if (root == NULL) {
        return 0;
    }
    // 先算子树
    int l = getNum(root->left);
    int r = getNum(root->right);
    // 最后算当前
    return root->val > 0 ? max(l, r) + 1 : max(l, r);



}
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
    cin >> k;
    while (k--) {
        cin >> n;
        arr.resize(n);
        node *root = NULL;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            root = build(root, arr[i]);
        }
        if (arr[0] < 0 || judge1(root) == false || judge2(root) == false) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}