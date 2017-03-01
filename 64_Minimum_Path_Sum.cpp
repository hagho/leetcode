class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, 0));
        cost[m - 1][n - 1] = grid[m - 1][n - 1];
        for (int i = m - 1;i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if(i + 1 <= m - 1 && j + 1 <= n - 1) {
                    cost[i][j] = min(cost[i + 1][j], cost[i][j + 1]) + grid[i][j];
                } else if (i + 1 <= m - 1 && j + 1 > n - 1) {
                    cost[i][j] = cost[i + 1][j] + grid[i][j];

                } else if (i + 1 > m - 1 && j + 1 <= n - 1) {
                    cost[i][j] = cost[i][j + 1] + grid[i][j];
                }
            }
        }
        return cost[0][0];
    }
};