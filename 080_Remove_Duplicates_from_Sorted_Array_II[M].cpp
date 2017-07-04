class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) {
            return nums.size();
        }
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (res < 2 || nums[res - 2] < nums[i]) {
                nums[res++] = nums[i];
            }
        }
        return res;
    }
};