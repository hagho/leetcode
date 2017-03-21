class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        if (nums.empty()) {
            return 0;
        }
        res.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            if (res.back() < nums[i]) {
                res.push_back(nums[i]);
            } else {
                *lower_bound(res.begin(), res.end(), nums[i]) = nums[i];
            }
        }
        return res.size();
    }
};