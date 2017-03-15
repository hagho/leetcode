class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0;
        dfs(nums, S, 0, 0, res);
        return res;
    }
private:
    void dfs(vector<int>& nums, int S, int i, int sum, int& res) {
        if (i >= nums.size()) {
            if (sum == S) {
                res++;
                return;
            }
            else {
                return;
            }
        }
        dfs(nums, S, i + 1, sum + nums[i], res);
        dfs(nums, S, i + 1, sum - nums[i], res);

    }
};