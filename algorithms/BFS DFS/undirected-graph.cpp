#include <vector>
#include <tuple>
#include <unordered_map>
#include <string>
#include <deque>
#include <unordered_set>
#include <iostream>

using namespace std;

unordered_map<string, vector<string>> createGraph(const vector<tuple<string, string>>& edges) {
    unordered_map<string, vector<string>> graph;
    for (auto [a, b] : edges) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    return graph;
}

bool undirectedPath(const vector<tuple<string, string>>& edges, const string& src, const string& dst) {
    if (src == dst) return true;

    unordered_map<string, vector<string>> graph = createGraph(edges);
    unordered_set<string> visited;

    deque<string> stack;
    stack.push_back(src);

    while (!stack.empty()) {
        string current = stack.back();
        stack.pop_back();

        if (current == dst) return true;

        if(visited.count(current)) continue;
        visited.insert(current);

        for (int i = graph[current].size()-1; i >= 0; --i) {
            stack.push_back(graph[current][i]);
        }
    }

    return false;
}

int main() {
    vector<tuple<string, string>> edges = {
        {"i", "j"},
        {"k", "i"},
        {"m", "k"},
        {"k", "l"},
        {"o", "n"}
    };

    cout << boolalpha << undirectedPath(edges, "j", "m") << endl;
    cout << boolalpha << undirectedPath(edges, "j", "o") << endl; 
}
