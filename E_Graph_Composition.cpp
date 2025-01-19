#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 2e5 + 5;

bool aplankyt2[MAX_NODES], aplankyt1[MAX_NODES];
int c1, c2, numNodes, edgespirmas, edgesGraph2, componentId[MAX_NODES];
vector<int> pirmas[MAX_NODES], graph2[MAX_NODES];
map<pair<int, int>, int> edgeMap;

void dfsGraph2(int node) {
    componentId[node] = c1;
    aplankyt2[node] = true;
    for (int kaim : graph2[node]) {
        if (!aplankyt2[kaim]) {
            dfsGraph2(kaim);
        }
    }
}

void dfspirmas(int node) {
    aplankyt1[node] = true;
    for (int kaim : pirmas[node]) {
        if (!aplankyt1[kaim] && edgeMap[{node, kaim}] != 1) {
            dfspirmas(kaim);
        }
    }
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        cin >> numNodes >> edgespirmas >> edgesGraph2;
        c1 = 0, c2 = 0;
        edgeMap.clear();

        for (int i = 0; i < numNodes; i++) {
            pirmas[i].clear();
            graph2[i].clear();
            aplankyt1[i] = false;
            aplankyt2[i] = false;
        }

        for (int i = 0; i < edgespirmas; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            pirmas[u].push_back(v);
            pirmas[v].push_back(u);
        }

        for (int i = 0; i < edgesGraph2; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            graph2[u].push_back(v);
            graph2[v].push_back(u);
        }

        for (int i = 0; i < numNodes; i++) {
            if (!aplankyt2[i]) {
                c1++;
                dfsGraph2(i);
            }
        }

        int ats = 0;
        for (int i = 0; i < numNodes; i++) {
            for (int kaim : pirmas[i]) {
                if (componentId[i] != componentId[kaim]) {
                    edgeMap[{i, kaim}] = 1;
                    ats++;
                }
            }
        }

        for (int i = 0; i < numNodes; i++) {
            if (!aplankyt1[i]) {
                c2++;
                dfspirmas(i);
            }
        }

        int skirt = c2 - c1;

        cout << ats / 2 + skirt << endl;
    }

    return 0;
}