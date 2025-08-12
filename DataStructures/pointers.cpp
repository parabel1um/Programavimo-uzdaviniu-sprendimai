#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi  vector<int>
#define vss vector<string>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vpp(T1, T2) vector<pair<T1, T2>>

struct Person {
    string name;
    int age;
};

void updateStruct(struct Person *person, int age) { // declare pointer in args to modify it
    //we always declare pointer with TYPE * NAME - same in args
    person->age = age; // -> is used when changing struct pointer variable
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // imagine pointers like this
    // imagine handing out pizzas at your own house
    // the flyer you hand out will be the pointer to the ADRESS OF THE HOUSE
    // thus we declare
    // pointer(flyer) has address
    // string *flyer = &house;
    // cout << *flyer << endl; -- tikras adresas
    // cout << flyer << endl; -- vieta lankstinuke
    // 
    // iskyrus jeigu norime pointeri priskirti masyvui
    //  cout << A[2] << endl; - adresas
    
    int x = 8;
    int* p = &x; // & for address of x, *p pointer;
    // pointer -> value, *(*p) pointer value;
    cout << p << endl; 

    struct Person variableNameOfStruct; // create a single variable of struct Person;
    updateStruct(&variableNameOfStruct, 10); // declare the address of the pointer, address can only be used with pointer
    cout << variableNameOfStruct.age << endl;

    return 0;
}