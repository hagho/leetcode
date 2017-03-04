class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                nums[i] = -1;
            }
        }
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0;i < nums.size(); i++) {
            sum += nums[i];
            if (m.find(sum) != m.end()) {
                result = max(result, i - m[sum]);
            } else {
                m[sum] = i;
            }
        }
        return result;
    }
};