class Solution {
public:
    int numSquares(int n) {
        vector<int> dp{0};
        while (dp.size() <= n) {
            int square = INT_MAX;
            for (int i = 1;i * i <= dp.size(); i++) {
                square = min(square, dp[dp.size() - i * i] + 1);
            }
            dp.push_back(square);
        }
        return dp[n];
    }
};