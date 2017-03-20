class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int m = abs(nums[i]) - 1;
            if (nums[m] < 0) {
                res.push_back(m + 1);
            } else {
                nums[m] = -nums[m];
            }
        }
        return res;
    }
};