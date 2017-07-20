class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        fun(nums, 0, res);
        return res;
    }
    void fun(vector<int> nums, int idx, vector<vector<int>>& res) {
        if (idx == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = idx;i < nums.size(); i++) {
            if (i != idx && nums[i] == nums[idx]) {
                continue;
            }
            swap(nums[i], nums[idx]);
            fun(nums, idx + 1, res);
        }
    }
};