class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int a = obstacleGrid.size();
        if (a == 0) {
            return 0;
        }
        int b = obstacleGrid[0].size();
        vector<vector<int>> dp(a, vector<int>(b, 0));
        for (int i = 0;i < a; i++) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = 1;
            } else {
                break;
            }
        }
        for (int j = 0; j < b; j++) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = 1;
            } else {
                break;
            }
        }
        for (int i = 1; i < a; i++) {
            for (int j = 1; j < b; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[a - 1][b - 1];
    }
};