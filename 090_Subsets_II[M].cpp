class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        dfs(nums, 0, res, vector<int>());
        return res;
    }
private:
    void dfs(vector<int>& nums, int index, vector<vector<int>>& res, vector<int> tmp) {
        res.push_back(tmp);
        for (int i = index;i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && i != index) {
                continue;
            }
            tmp.push_back(nums[i]);
            dfs(nums, i + 1, res, tmp);
            tmp.pop_back();
        }
    }
};