class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int ed = nums.size() - 1;
        while (st < ed) {
            int mid = st + ( ed - st ) / 2;
            if (( target < nums[0] ) == ( nums[mid] < nums[0] )) {
                if (target < nums[mid]) {
                    ed = mid;
                }
                if (target > nums[mid]) {
                    st = mid + 1;
                }
                if (target == nums[mid]) {
                    return mid;
                }
            }  else {
                if (target < nums[0]) {
                    st = mid + 1;
                } else {
                    ed = mid;
                }
            }
        }
        if (nums.size() ==  0) {
            return -1;
        }
        if (nums[st] == target) {
            return st;
        }
        return -1;
    }
};