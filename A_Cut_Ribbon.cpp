#include <bits/stdc++.h>
using namespace std;

int maxPieces(int n, vector<int>& pieces, unordered_map<int, int>& memo) {
    if(n==0) return 0;
    if(n<0) return -1;
    if(memo.count(n)) return memo[n];     //memoization approach

    int ans = -1; // pradedame su -1, nes galime supjaustyti į nei vieną, t.y. nepalikti be pjūvių(vientiso, su 0 pjūvių)
    for(int piece:pieces){
        if(piece<=n) {
            int prev=maxPieces(n-piece, pieces, memo);
            if(prev!=-1) { //jeigu neigiama praleidžiame pavyzdžiui 7-5-5=-3, bet mums reikia tik vieno -5
                ans=max(ans, 1+prev);
            }
        }
    }
    memo[n]=ans;
    return ans;
}

int main() {
    int n;cin>>n;
    vector<int> pieces(3);
    unordered_map<int, int> memo;
    for(int i=0;i<3;i++) {
        cin>>pieces[i];
    }
    cout<<maxPieces(n, pieces, memo);
}