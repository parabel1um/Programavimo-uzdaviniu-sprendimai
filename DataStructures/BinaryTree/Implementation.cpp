#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi  vector<int>
#define vss vector<string>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vpp(T1, T2) vector<pair<T1, T2>>

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* createNewNode(int data) {
    BstNode* newNode = new BstNode(); // returns address of new Node
    // use -> when we want to access struct using a pointer
    newNode->data=data;
    newNode->left=NULL; // we create completely empty node NOT ALLOCATED to anything
    newNode->right=NULL;
    return newNode;  
}

//arguments: where, root, and what, data
// here we could use ** if we wanted to change THE ACTUAL POINTER, MAKE IT NOT POINT TO NULL
BstNode* Insert(BstNode* root, int data) {
    if (root == nullptr) {
        root = createNewNode(data); // for the insertion of 13 (last one) example is provided
    } else if (data <= root->data) { // first, we compare TO ALL VALUES OF ROOT ONE SIDE
        //second, we call insert function by passing left of root, but root left remains unchanged
        root->left = Insert(root->left, data); // here left is currently NULL, that means we will create a new one
    } else {
        root->right = Insert(root->right, data); // same here
    }
    return root;
}

bool Search(BstNode* root, int data) {
    if(root==NULL) return false;
    if(root->data==data) return true;
    if(data<=root->data) return Search(root->left, data);
    return Search(root->right, data);
}

// Nodes nėra tarpusavyje susiję(nesaugomi array formate), nauji elementai yra sukuriami atskirai ir jie turi adresus į kairinius ir dešininius nodes. 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    BstNode* root = NULL; // šitas nekinta
    root=Insert(root, 20);
    root=Insert(root, 12);
    root=Insert(root, 11);
    root=Insert(root, 13);

    if(Search(root, 12)) cout<<"Found\n";
    else cout<<"Not Found\n";

    return 0;
}