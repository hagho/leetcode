class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        for (int i = 0; i < nums.size(); i++) {
            twos |= ones & nums[i];
            ones ^= nums[i];
            int t = twos & ones;
            ones &= ~t;
            twos &= ~t;
        }
        return ones;
    }
};