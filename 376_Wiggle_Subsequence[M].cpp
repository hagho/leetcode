class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int res = 1;
        int tmp = 2; 
        if (nums.empty()) {
            return 0;
        }
        int cnt = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (( nums[i] - cnt ) > 0 && tmp != 1 ) {
                tmp = 1;
                res++;
            } else if (( nums[i] - cnt) < 0 && tmp != 0) {
                tmp = 0;
                res++;
            }
            cnt = nums[i];
        }
        return res;
    }
};