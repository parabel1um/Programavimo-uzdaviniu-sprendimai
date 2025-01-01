#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int MAX_N = 10000;
const int MAX_M = 10000;
const int INF = 1e9;

int n, m;
char maze[MAX_N][MAX_M];
pair<int, int> start, end;

// Directions: up, down, left, right
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct State {
    int x, y, steps, last_direction, count;
};

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] != '#';
}

int bfs() {
    queue<State> q;
    vector<vector<vector<vector<bool>>>> visited(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(4, vector<bool>(4, false))));
    
    // Initialize the queue with all possible directions from the start
    for (int d = 0; d < 4; ++d) {
        q.push({start.first, start.second, 0, d, 0});
        visited[start.first][start.second][d][0] = true;
    }

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        // If we reached the end position
        if (current.x == end.first && current.y == end.second) {
            return current.steps;
        }

        // Explore all directions
        for (int d = 0; d < 4; ++d) {
            int nx = current.x + dx[d];
            int ny = current.y + dy[d];

            if (is_valid(nx, ny)) {
                int new_count = (d == current.last_direction) ? current.count + 1 : 1;

                // Only proceed if we haven't exceeded the consecutive step limit
                if (new_count <= 3 && !visited[nx][ny][d][new_count]) {
                    visited[nx][ny][d][new_count] = true;
                    q.push({nx, ny, current.steps + 1, d, new_count});
                }
            }
        }
    }

    return -1; // If we exhaust the queue without finding the end
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> maze[i];
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == 'S') {
                start = {i, j};
            } else if (maze[i][j] == 'T') {
                end = {i, j};
            }
        }
    }

    int result = bfs();
    cout << result << endl;

    return 0;
}