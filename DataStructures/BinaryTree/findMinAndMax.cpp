#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi  vector<int>
#define vss vector<string>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vpp(T1, T2) vector<pair<T1, T2>>

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

int FindMin(BSTNode* root) {
    if(root==NULL) return -1;
    BSTNode* curr=root;
    while(curr->left!=NULL) curr=curr->left;
    return curr->data;
}

int FindMax(BSTNode* root) {
    if(root==NULL) return -1;
    BSTNode* curr=root;
    while(curr->right!=NULL) curr=curr->right;
    return curr->data;
}


BSTNode* createNewNode(int data) {
    BSTNode* newNode = new BSTNode();
    newNode->data=data;
    newNode->right=NULL;
    newNode->left=NULL;
    return newNode;
}

BSTNode* Insert(BSTNode* root, int data) {
    if(root==NULL) return createNewNode(data);
    else if(data<=root->data) root->left=Insert(root->left, data);
    else root->right=Insert(root->right, data);
    return root;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    BSTNode *root=NULL;
    root=Insert(root, 25);
    root=Insert(root, 15);
    root=Insert(root, 50);
    root=Insert(root, 10);
    root=Insert(root, 22);
    root=Insert(root, 35);
    root=Insert(root, 70);
    root=Insert(root, 4);
    root=Insert(root, 12);
    root=Insert(root, 18);
    root=Insert(root, 24);
    root=Insert(root, 31);
    root=Insert(root, 44);
    root=Insert(root, 66);
    root=Insert(root, 90);
    
    cout<<"Min: "<<FindMin(root)<<"\nMax: "<<FindMax(root);

    return 0;
}