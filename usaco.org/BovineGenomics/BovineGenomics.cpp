#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int N, M, spotted = 0;
    cin >> N >> M; // M - x, N - y
    vector<vector<char>> A(M, vector<char>(N * 2));

    for(int i = 0; i < N; i++){
        string g;
        cin >> g;
        for(int j = 0; j < M; j++){
            A[j][i] = g[j];
        }
    }

    for(int i = 0; i < N; i++){
        string g;
        cin >> g;
        for(int j = 0; j < M; j++){
            A[j][i + N] = g[j];
        }
    }

    for(int x = 0; x < M; x++){
        set<char> spot;
        bool skirt = true;
        for(int y = 0; y < N; y++){
            spot.insert(A[x][y]);
        }

        for(int y = N; y < 2 * N; y++){
            if(spot.count(A[x][y])){
                skirt = false;
                break;
            }
        }
        if(skirt) spotted++;
    }

    cout << spotted << endl;
    return 0;
}
