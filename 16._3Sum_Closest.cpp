#include <vector>
#include <algorithm>

using verctor<int>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int min = nums[0] + nums[1] + nums[2];
        for(int left = 0; left < nums.size() - 2; left++) {
            int mid = left + 1;
            int right = nums.size() - 1;
            int temp = target - nums[left];
            while(mid < right) {
                if(abs(temp - (nums[mid] + nums[right]) ) < abs(target - min)) {
                    min = nums[left] + nums[mid] + nums[right];
                }
                if(nums[mid] + nums[right] == temp) {
                    return target;
                } 
                if(nums[mid] + nums[right] < temp) {
                    mid++;
                }
                if(nums[mid] + nums[right] > temp) {
                    right--;
                }
            }
        }
        return min;
    }
};