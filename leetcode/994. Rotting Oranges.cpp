class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(); // eilutes
        int cols = grid[0].size();

        queue<pair<int,int>> q; // supuvusiu vietos
        int minutes=0,fresh=0;

        for(int i=0;i<rows;i++) {
            for (int j=0;j<cols;j++) {
                if(grid[i][j]==2) {
                    q.push({i,j});
                } else if (grid[i][j]==1) fresh++;
            }
        }

        // kad neiseitume is ribu, galime susikurti visu krypciu masyva

        vector<pair<int, int>> kryptys = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while(!q.empty()) {
            int dydis=q.size(); // kiek elementu nagrinesime si karta

            bool rot=false;
            for (int i=0;i<dydis;i++) {
                auto [r, c] = q.front(); // dabartinis
                q.pop();

                for(auto [x, y]: kryptys) {
                    int eil = x+r, stulp=y+c;
                    if(eil>=0 && stulp>=0 && eil<rows && stulp<cols && grid[eil][stulp]==1) {
                        grid[eil][stulp]=2;
                        q.push({eil, stulp});
                        rot=true;
                        fresh--;
                    }
                }
            }

            if(rot) minutes++;
        }

        if(fresh!=0) return -1;
        return minutes;
    }
};