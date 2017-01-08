#include <vector>

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = vector<int>({-1, -1});
        int st = 0;
        int ed = nums.size() - 1;
        if (nums.size() == 0) {
            return result;
        }
        //寻找左边界
        while (st < ed) {
            int mid = st + (ed - st) / 2;
            if (nums[mid] < target) {
                st = mid + 1;
            } else {
                ed = mid;
            }

        }
        if (nums[st] != target) {
            return result;
        }
        result[0] = st;
        //寻找右边界
        ed = nums.size() - 1;
        while (st < ed) {
            int mid = st + (ed - st) / 2 + 1;
            if(nums[mid] > target) {
                ed = mid - 1;
            } else {
                st = mid;
            }
        }
        result[1] = ed;
        return result;
    }
};
