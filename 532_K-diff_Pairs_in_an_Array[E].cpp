class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if (nums.size() < 2) {
            return 0;
        }
        int res = 0;
        int a = 0;
        int b = 1;
        while(b < nums.size()) {
            if (nums[b] - nums[a] == k) {
                res++;
                while (a < nums.size() && nums[++a] == nums[a - 1]);
                b = a + 1;
                continue;
            }
            if (nums[b] - nums[a] > k) {
                a++;
                if (b == a) {
                    b++;
                }
                continue;
            }
            while (b < nums.size() && nums[++b] == nums[b - 1]);
        }
        return res;

    }
};