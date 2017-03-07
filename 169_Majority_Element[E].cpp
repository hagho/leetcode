class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int t = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (majority == nums[i]) {
                t++;
            } else {
                t--;
            }
            if (t == 0) {
                majority = nums[i];
                t= 1;
            }
        }
        return majority;
    }
};