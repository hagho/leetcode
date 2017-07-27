class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int st = 0;
        int ed = 0;
        if (nums.empty()) {
            return res;
        }
        if (nums.size() == 1) {
            res.push_back(to_string(nums[0]));
            return res;
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                ed++;
            } else {
                if (st != ed) {
                    res.push_back(to_string(nums[st]) + "->" + to_string(nums[ed]));
                } else {
                   res.push_back(to_string(nums[st])); 
                }
                st = i;
                ed = i;
            }
        }
        if (st != ed) {
            res.push_back(to_string(nums[st]) + "->" + to_string(nums[ed]));
        } else {
            res.push_back(to_string(nums[st]));
        }
        return res;
    }
};