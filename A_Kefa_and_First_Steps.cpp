#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Ivedimas(vector<int>& a, int& n);
void Skaiciavimas(vector<int>& a, int& n, int& k);

int main() {
    int n, k = 0;
    vector<int> a;
    Ivedimas(a, n);
    Skaiciavimas(a, n, k);
    cout<<k;
}

void Ivedimas(vector<int>& a, int& n) {
    cin>>n; a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void Skaiciavimas(vector<int>& a, int& n, int& k) {
    int u = 1;
    k = 1;
    for(int i = 0; i < n-1; i++) {
        if(a[i+1] >= a[i]) {
            u++;
            k = max(k, u);
        } else {
            u = 1;
        }
    }
}

