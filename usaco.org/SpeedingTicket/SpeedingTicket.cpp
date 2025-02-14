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
    scanf("%d %d", &N, &M);
    
    vector<Segment> NS(N), MS(M);

    for (int i = 0; i < N; i++) {
        cin >> NS[i].length >> NS[i].speed;
    }

    for (int i = 0; i < M; i++) {
        cin >> MS[i].length >> MS[i].speed;
    }

    int j = 0, k = 0; // j - greicio limitas , k - karves
    int atslikj = MS[0].length, atslikk = NS[0].length;

    while (k < N && j < M) {
        if (MS[j].speed > NS[k].speed) {
            maxo = max(maxo, MS[j].speed - NS[k].speed);
        }        
        int skirt = min(atslikj, atslikk);

        atslikj -= skirt;
        atslikk -= skirt;

        if (atslikj == 0 && j + 1 <= M) { 
            j++;
            atslikj = MS[j].length;
        }

        if (atslikk == 0 && k + 1 <= N) { 
            k++;
            atslikk = NS[k].length;
        }
    }

    cout << maxo << endl;
    return 0;
}
