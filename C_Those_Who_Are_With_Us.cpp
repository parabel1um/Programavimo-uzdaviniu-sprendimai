#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;cin>>t;
    while(t--) {
        int n,m;cin>>n>>m;
        unordered_map<int,int> freq;
        vector<vector<int>> A(n,vector<int>(m));
        vector<int> eilesDidziausias(n,0), stulpelisDidziausias(m,0);
        int visuDidziausias=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>A[i][j];
                freq[A[i][j]]++;
                visuDidziausias=max(visuDidziausias,A[i][j]);
                eilesDidziausias[i]=max(eilesDidziausias[i],A[i][j]);
                stulpelisDidziausias[j]=max(stulpelisDidziausias[j],A[i][j]);
            }
        }
        int maksimumoKiekis=0;
        vector<int> eileDid(n,0), stulpDid(m,0);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(A[i][j]==visuDidziausias) {
                    eileDid[i]++;
                    stulpDid[j]++;
                }
            }
        }

        int antrasNuoGalo=0;
        for(auto [f,s]:freq){
            if(f!=visuDidziausias){
                antrasNuoGalo=max(antrasNuoGalo,f);
            }
        }

        int ans=INT_MAX;
        for(int r=0;r<n;r++) {
            for(int c=0;c<m;c++) {
                int skirt=0;
                bool visiPasalinti;
                if(A[r][c]==visuDidziausias) skirt=1;
                int eileSumazinta;
                if (eilesDidziausias[r] == visuDidziausias) {
                    eileSumazinta = eilesDidziausias[r] - 1;
                } else {
                    eileSumazinta = eilesDidziausias[r];
                }

                int StulpSumazint;
                if (stulpelisDidziausias[c] == visuDidziausias) {
                    StulpSumazint = stulpelisDidziausias[c] - 1;
                } else {
                    StulpSumazint = stulpelisDidziausias[c];
                }

                int didSkait=max(eileSumazinta,StulpSumazint);
                int naujas;
                if(eileDid[r]+stulpDid[c]-skirt==freq[visuDidziausias]) {
                    naujas=max(antrasNuoGalo,didSkait);
                } else{
                    naujas=max(visuDidziausias,didSkait);
                }
                ans=min(ans,naujas);
            }
        }
        cout<<ans<<endl;
    }
}