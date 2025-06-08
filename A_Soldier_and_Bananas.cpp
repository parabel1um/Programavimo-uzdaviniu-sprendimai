#include <bits/stdc++.h>
using namespace std;
int main() {
    int k, n, w, total=0; cin>>k>>n>>w;
    for(int i =0;i<w;i++) total+=k*(i+1);
    cout<<max(total-n, 0)<<endl;
    //kiek reikia is viso nusipikti visus bananus

}