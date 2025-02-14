#include <bits/stdc++.h>
using namespace std;

struct Bucket{
    int capacity;
    int current;
};

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    vector<Bucket> A(3);
    for(int i = 0; i < 3; i++){
        scanf("%d %d", &A[i].capacity, &A[i].current);
    }

    for (int i = 0; i < 100; i++){
        int is = i%3;
        int in = (i+1)%3;
        int amount = min(A[is].current, A[in].capacity - A[in].current);
        A[in].current += amount;
        A[is].current -= amount;
    }

    cout << A[0].current << endl << A[1].current << endl << A[2].current << endl;

    return 0;
}