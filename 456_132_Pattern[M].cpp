class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = 1;
            } else {
                m[nums[i]]++;
            }
        }
        int minValue = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]--;
            if (m[nums[i]] == 0) {
                m.erase(nums[i]);
            }
            if (nums[i] < minValue) {
                minValue = nums[i];
            } else {
                if (m.upper_bound(minValue) != m.end() && m.upper_bound(minValue)->first < nums[i] ) {
                    return true;
                }
            }
        }
        return false;
    }
};