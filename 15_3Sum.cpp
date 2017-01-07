#include <vector>
#include <algorithm>

using verctor<int>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        for(int left = 0; left < nums.size() && nums[left] <= 0; left++) {
            if(left != 0 && nums[left] == nums[left - 1]) {
                continue;
            }
            int mid = left + 1;
            int right = nums.size() - 1;
            int temp = 0 - nums[left];
            while(mid < right) {
                if(nums[mid] + nums[right] == temp) {
                    result.push_back(vector<int>({nums[left], nums[mid], nums[right]}));
                    mid++;
                    right--;
                    while(nums[mid] == nums[mid - 1]) {
                        mid++;
                        continue;
                    }
                    while(nums[right] == nums[right + 1]) {
                        right--;
                        continue;
                    }
                } 
                if(nums[mid] + nums[right] < temp) {
                    mid++;
                }
                if(nums[mid] + nums[right] > temp) {
                    right--;
                }
            }
        }
        return result;
    }
};