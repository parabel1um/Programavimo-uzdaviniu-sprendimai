#include <bits/stdc++.h>
using namespace std;
//nereikia sudaryti graph, nes kiekvienas yra skirtingas ir ir turi tik po vieną edge
int main() {
    int n; cin>>n;
    vector<int> f(n+1);
    for (int i=1;i<=n;i++) cin>>f[i];
    for (int i=1;i<=n;i++) {
        queue<pair<int,int>> q;
        q.push({i, 0}); // {curr, zingsniu skaicius} zingsniu skaicius nes svarbu, jog butu tik 3 curr=i
        unordered_set<int> visited(n+1);
        visited.insert(i); // i=current
        while (!q.empty()) {
            auto [curr, dist]=q.front();
            q.pop();
            int nxt = f[curr];
            if (!visited.count(nxt)) { // classic BFS
                visited.insert(nxt);
                q.push({nxt, dist+1});
            }
            else if (nxt == i && dist + 1 == 3) { // check if we come back to start
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";
    return 0;
}
