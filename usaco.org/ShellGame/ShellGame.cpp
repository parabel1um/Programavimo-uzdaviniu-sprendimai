#include <bits/stdc++.h>
using namespace std;

int main() 
{
    freopen("shell.in", "r", stdin);
    int n;
    scanf("%d", &n);
    
    vector<int> counte(3, 0);
    vector<int> b = {1, 2, 3};
    for (int i = 0; i < n; ++i) {
        int x, y, g;
        scanf("%d %d %d", &x, &y, &g);
        x--; y--; g--;
        swap(b[x], b[y]);
        counte[b[g] - 1]++;
    }
    freopen("shell.out", "w", stdout);
    cout << *max_element(counte.begin(), counte.end()) << endl;

    return 0;
}