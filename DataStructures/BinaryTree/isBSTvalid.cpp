#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* createNewNode(int data) {
    return new TreeNode(data);
}

TreeNode* Insert(TreeNode* root, int data) {
    if (root == NULL) return createNewNode(data);
    if (data <= root->val) root->left = Insert(root->left, data);
    else root->right = Insert(root->right, data);
    return root;
}

int heightOfTree(TreeNode *root) {
    if (root == nullptr) return -1;
    int lHeight = heightOfTree(root->left);
    int rHeight = heightOfTree(root->right);
    return max(lHeight, rHeight) + 1;
}

int heightOfTreeByUsingQueue(TreeNode* root) {
    if (root == NULL) return 0;
    int currHeight = -1;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left != NULL) q.push(curr->left);
            if (curr->right != NULL) q.push(curr->right);
        }
        currHeight++;
    }
    return currHeight;
}

class Solution {
public:
    bool isSubTreeSmaller(TreeNode* root, int comparable) {
        if(root==NULL) return true;
        if(root->val < comparable) {
            if(isSubTreeSmaller(root->left, comparable) && isSubTreeSmaller(root->right, comparable))
                return true;
        }
        return false;
    }

    bool isSubTreeBigger(TreeNode* root, int comparable) {
        if(root==NULL) return true;
        if(root->val > comparable) {
            if(isSubTreeBigger(root->left, comparable) && isSubTreeBigger(root->right, comparable))
                return true;
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        if(isSubTreeSmaller(root->left, root->val) && isSubTreeBigger(root->right, root->val)) {
            if(isValidBST(root->left) && isValidBST(root->right)) {
                return true;
            }
        } 
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    TreeNode *root = NULL;
    root = Insert(root, 25);
    root = Insert(root, 15);
    root = Insert(root, 50);
    root = Insert(root, 10);
    root = Insert(root, 22);
    root = Insert(root, 35);
    root = Insert(root, 70);
    root = Insert(root, 4);
    root = Insert(root, 12);
    root = Insert(root, 18);
    root = Insert(root, 24);
    root = Insert(root, 31);
    root = Insert(root, 44);
    root = Insert(root, 66);
    root = Insert(root, 90);

    Solution sol;
    cout << (sol.isValidBST(root) ? "Yes" : "No") << "\n";

    return 0;
}
