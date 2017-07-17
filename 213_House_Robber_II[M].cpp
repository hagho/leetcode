class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        vector<int> a(nums.begin(), nums.end() - 1);
        vector<int> b(nums.begin() + 1, nums.end());
        return max(rob_original(a), rob_original(b));      
    }
    int rob_original(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        res[0] = nums[0];
        res[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            res[i] = max(res[i - 1], res[i - 2] + nums[i]);
        }
        return res[nums.size() - 1];
    }
};