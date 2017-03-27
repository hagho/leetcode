class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index;
        int l = 0;
        int r = nums.size();
        while (l <= r && l < nums.size()) {
            int mid = l + ( r - l ) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                r = mid - 1;
                continue;
            }
            if (nums[mid] < target) {
                l = mid + 1;
            }
        }
        return l;
    }
};