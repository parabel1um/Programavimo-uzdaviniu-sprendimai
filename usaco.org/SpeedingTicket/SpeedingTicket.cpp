#include <bits/stdc++.h>
using namespace std;

struct Segment {
    int speed;
    int length;
};

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int N, M, maxo = 0;
    cin>>N>>M;
    vector<Segment> NS(N);
    vector<Segment> MS(M);

    for (int i=0;i<N;i++){
        cin>>NS[i].length>>NS[i].speed;
    };

    for (int i=0;i<M;i++){
        cin>>MS[i].length>>MS[i].speed;
    }

    int j = 0, k=0; // kelio segmento ilgis teisetas k karves vaziuoto j de facto;
    int atsj = 0, atsk = 0;

    while (atsj<100 && atsk<100) {
        maxo = max(maxo, MS[k].speed - NS[j].speed);
        
        if(NS[j].length < MS[k].length) {
            atsj += NS[j].length;
            MS[k].length -= NS[j].length; // nes mums liko
            j++;
        } else if (NS[j].length == MS[j].length) {
            atsj += NS[j].length;
            j++;
            atsk += MS[k].length;
            k++;
        } else {
            atsk += MS[k].length;
            NS[j].length -= MS[k].length; // nes dar liko
            k++;
        }
    }

    cout<<maxo<<endl;

    return 0;
}