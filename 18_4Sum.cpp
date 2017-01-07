class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        if(nums.size() < 4) {
            return vector<vector<int>>();
        }
        vector<vector<int>> result;
        int max = *(nums.end() - 1);
        for(int a = 0; a < nums.size() - 2; a++) {
            if(nums[a] + 3 * max < target) {
                continue;
            }
            if(nums[a] * 4 > target) {
                break;
            }
            while(a > 0 && nums[a] == nums[a - 1]) {
                a++;
            }
            int target_for_threesum = target - nums[a];
            for(int b = a + 1; b < nums.size() - 1; b++) {
                if(nums[b] + 2 * max < target_for_threesum) {
                    continue;
                }
                if(nums[b] * 3 > target_for_threesum) {
                    break;
                }
                while(b > a + 1 && nums[b] == nums[b - 1]) {
                    b++;
                }
                int temp = target_for_threesum - nums[b];
                int c = b + 1;
                int d = nums.size() - 1;
                while(c < d) {
                    if(nums[c] + nums[d] == temp) {
                        result.push_back(vector<int>({nums[a], nums[b], nums[c], nums[d]}));
                        c++;
                        d--;
                        while(nums[c] == nums[c - 1]) {
                            c++;
                        }
                        while(nums[d] == nums[d + 1]) {
                            d--;
                        }
                    }
                    if(nums[c] + nums[d] < temp) {
                        c++;
                    }
                    if(nums[c] + nums[d] > temp) {
                        d--;
                    }
                }
            }
        }
        return result;
    }
};