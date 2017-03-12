#include <numeric>
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0;
        /*
        while (!equalInArray(nums)) {
            sort(nums.begin(), nums.end());
            for(int i = 0; i < nums.size() - 1; i++) {
                nums[i]++;
            }
        }
        */

        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (nums.empty()) {
            return res;
        }
        sort(nums.begin(), nums.end());
        res = sum - nums[0] * nums.size(); 
        return res;
    }
/*
private:
    bool equalInArray(vector<int>& nums) {
        if (nums.empty()) {
            return true;
        }
        int temp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != temp){
                return false;
            }
        }
        return true;
    }
*/
};