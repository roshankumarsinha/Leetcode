class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int row = grid.size();
        int col = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if (fresh == 0)
            return time;
        vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int size = q.size();
            bool flag = false;
            for (int i = 0; i < size; i++) {
                int rowRotten = q.front().first;
                int colRotten = q.front().second;
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int newRow = rowRotten + d[j].first;
                    int newCol = colRotten + d[j].second;
                    if (newRow >= 0 && newRow < row && newCol >= 0 &&
                        newCol < col && grid[newRow][newCol] == 1) {
                        flag = true;
                        grid[newRow][newCol] = 2;
                        fresh--;
                        q.push({newRow, newCol});
                    }
                }
            }
            if (flag) {
                time++;
            }
        }
        return fresh > 0 ? -1 : time;
    }
};