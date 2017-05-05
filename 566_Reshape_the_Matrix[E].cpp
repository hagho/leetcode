class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size();
        int m = nums[0].size();
        if (n * m != r * c) {
            return nums;
        }
        vector<vector<int>> res(r,vector<int>(c, 0));
        int nn = 0;
        int mm = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res[i][j] = nums[nn][mm];
                mm++;
                if (mm == m) {
                    nn++;
                    mm = 0;
                }
            }
        }
        return res;
    }
};