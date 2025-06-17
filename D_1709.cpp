#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int> A(n), B(n);
        for (int i=0;i<n;i++) cin>>A[i];
        for (int i=0;i<n;i++) cin>>B[i];
        vector<pair<int, int>> ejimai;
       
        for (int i=0;i<n;i++) { // Mėginame apkeisti kaimyninius skaičius naudojant Bubble sort
            for (int j=0;j+1<n;j++) {
                if(A[j]>A[j+1]) {
                    swap(A[j], A[j+1]);
                    ejimai.push_back(make_pair(1,j+1));
                }
                if(B[j]>B[j+1]) {
                    swap(B[j], B[j+1]);
                    ejimai.push_back(make_pair(2,j+1));
                }
            }
        }
 
        for (int i=0;i<n;i++) {
            if (A[i]>B[i]) {
                swap(A[i],B[i]);
                ejimai.push_back(make_pair(3, i+1));
            }
        }
 
        cout<<ejimai.size()<<endl;
        for (auto [f,s]: ejimai) {
            cout<<f<<' '<<s<<endl;
        }
    }
 
    return 0;
}