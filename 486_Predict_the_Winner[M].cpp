class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return canWin(nums, 0, n - 1, dp) >= 0;
    }

private:
    int canWin(vector<int>& nums, int st, int ed, vector<vector<int>>& dp) {
        if (dp[st][ed] == -1) {
            dp[st][ed] = (st == ed) ? nums[st] : max(nums[st] - canWin(nums, st + 1, ed, dp), nums[ed] - canWin(nums, st, ed - 1, dp));
        }
        return dp[st][ed];
    }
};