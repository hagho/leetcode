class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0;i < nums.size(); i++) {
            res ^= nums[i];
        }
        int lastbit = ( res & (res - 1) ) ^ res;
        int a = 0;
        int b = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & lastbit) {
                a ^= nums[i];
            } else {
                b ^= nums[i];
            }
        }
        return vector<int>{a, b};
    }
};