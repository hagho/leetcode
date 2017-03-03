class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        int newlen = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i-1]) nums[newlen++] = nums[i];
        }
        return newlen;
    }
private:
    void swap(int& a, int& b) {
        a^=b;
        b^=a;
        a^=b;
    }
};