class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1 ; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                for (int j = nums.size() - 1; j >= i; j--) {
                    if (nums[j] > nums[i - 1]) {
                        swap(nums[j], nums[i - 1]);
                        sort(nums.begin() + i, nums.end());
                        return ;
                    }
                }
            }
        }
        sort(nums.begin(), nums.end());
        return ;
    }
private:
    void swap(int &a, int &b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
};