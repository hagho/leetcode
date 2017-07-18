class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) {
            return vector<int>();
        }
        vector<int> dp(nums.size(), 1);
        vector<int> pre(nums.size(), -1);
        sort(nums.begin(), nums.end());
        for (int i = 0;i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < dp.size(); i++) {
            if (dp[i] > dp[ans]) {
                ans = i;
            }
        }
        vector<int> res;
        while (ans != -1) {
            res.push_back(nums[ans]);
            ans = pre[ans];
        }
        return res;
    }
};