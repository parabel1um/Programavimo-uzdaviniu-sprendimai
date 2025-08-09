#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi  vector<int>
#define vss vector<string>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vpp(T1, T2) vector<pair<T1, T2>>

struct Node {
    int data;
    Node *next; // pointer to ANOTHER node, POINTER OF ENTIRE NODE
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // declaring pointers, only containing address in memory
    Node* h; // head
    Node* t; // temp
    Node* n;

    n= new Node; // new Node - CREATES A STRUCT AND RETURNS A POINTER to randomly allocated in memory;
    // we have a EMPTY type which we FILL with RANDOMLY ALLOCATED (USING ENW KEYWORD)
    // so pointer type MUST MATCH new type
    n->data=10; 

    

    return 0;
}