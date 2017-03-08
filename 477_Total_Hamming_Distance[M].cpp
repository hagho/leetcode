class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            for(int j = 0; j < nums.size(); j++) {
                if (nums[j] >> i & 1 == 1) {
                    cnt++;
                }
            }
            res += cnt * (nums.size() - cnt);
        }
        return res;
        /*
        int res = 0;
        for (int i = 0;i < nums.size(); i++) {
            for (int j = i + 1;j < nums.size(); j++) {
                res += hammingDistance(nums[i], nums[j]);
            }
        }
        return res;
        */
    }
/*
private:
    int hammingDistance(int a, int b) {
        int c = a ^ b;
        int d = 0;
        for(; c; d++) {
            c &= ( c - 1 )
        }
        return d;
    }
*/
};