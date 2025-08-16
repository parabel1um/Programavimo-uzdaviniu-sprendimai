#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi  vector<int>
#define vss vector<string>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vpp(T1, T2) vector<pair<T1, T2>>
#define max 10000

class Stack {
    int arr[max];
    int top;

public:
    Stack(): top(-1) {} // so top is -1 array is empty

    bool isEmpty() { return top == -1;}
    bool isFull() { return top == max-1;}

    void push(int x) {
        if(isFull()) return;
        arr[++top] = x; // position bigger than top by 1 place the element
    }

    void pop() {
        if (isEmpty()) return;
        top--;
    }

    int peek() {
        if(isEmpty()) return -1;
        return arr[top];
    }
};

int main(){
    Stack s;
    s.push(20);
    s.push(30);
    cout<<"Top is at "<<s.peek()<<endl;
    return 0;
}