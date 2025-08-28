class Solution {
public:
            void bfs(int i, int j, set<pair<int, int>>& visited, vector<vector<char>> grid) {
            visited.insert({i, j});
            deque<pair<int, int>> current;
            current.push_back({i, j});
            
            while(!current.empty()) {
                int row = current[0].first;
                int col = current[0].second;
                current.pop_front();
                int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

                for(int i = 0;i<4;i++){
                    int newRow = row + directions[i][0];
                    int newCol = col + directions[i][1];

                    if (newCol >= 0 && newRow >= 0 && newRow < grid.size() && newCol < grid[0].size() && grid[newRow][newCol] == '1' && visited.find({newRow, newCol}) == visited.end()) {
                        visited.insert({newRow, newCol});
                        current.push_back({newRow, newCol});
                    }
                }

            }
        }

    int numIslands(vector<vector<char>>& grid) {
        set<pair<int, int>> visited;
        int k = 0;
        for (int i = 0; i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1' && visited.find({i, j}) == visited.end()) {
                    bfs(i, j, visited, grid);
                    k++;
                }
            }
        }
        return k;
    }
};

