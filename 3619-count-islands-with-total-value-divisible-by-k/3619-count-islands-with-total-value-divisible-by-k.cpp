class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;

                long long sum = 0;
                stack<pair<int,int>> st;
                st.push({i, j});
                sum += grid[i][j];
                grid[i][j] = 0; // mark visited

                while (!st.empty()) {
                    auto [x, y] = st.top();
                    st.pop();
                    for (auto& d : dirs) {
                        int nx = x + d[0], ny = y + d[1];
                        if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == 0) continue;
                        sum += grid[nx][ny];
                        grid[nx][ny] = 0;
                        st.push({nx, ny});
                    }
                }

                if (sum % k == 0) count++;
            }
        }
        return count;
    }
};