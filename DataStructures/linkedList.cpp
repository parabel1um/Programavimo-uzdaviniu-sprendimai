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

// we insert it at the very front of the list
void insert(Node* &head, int data) { // head is passed by reference 
    // head - node pointing to, data, inserted
    Node* tempPtr = new Node;
    tempPtr->data = data;
    tempPtr->next = head; // head, without a pointer, returns an address
    head = tempPtr; // tempPtr is a pointer
    // head address STAYS THE SAME // meaning we still can access it because we have variable for it in main code
    // but content changes 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // THERES NO PREDEFINED LIST, WE JUST NEED TO KNOW ADDRESSES

    // declaring pointers, only containing address in memory
    Node* h; // head
    h=new Node;
    h->data=20;
    h->next=NULL;

    insert(h, 20);
    insert(h, 30);

    Node* tempPtr = h;
    while (tempPtr != nullptr){
        cout << tempPtr->data << "\n";
        tempPtr = tempPtr->next;
    }

    return 0;
}