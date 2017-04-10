class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int frombegin = 1;
        int fromlast = 1;
        for (int i = 0;i < nums.size(); i++) {
            res[i] *= frombegin;
            frombegin *= nums[i];
            res[nums.size() - 1 - i] *= fromlast;
            fromlast *= nums[nums.size() - 1 - i];
        }
        return res;
    }
};