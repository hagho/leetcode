class Solution {
public:
    Solution(vector<int> nums): nums(nums) {
        t = 0;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result;
        int n = nums.size();
        srand(time(0) + t);
        t++;
        vector<bool> flag(n, false);
        for (int i = 0; i < n; i++) {
            int j = rand() % n;
            while (flag[j]) {
                j = rand() % n;
            }
            flag[j] = true;
            result.push_back(nums[j]);
        }
        return result;
    }
private:
    vector<int> nums;
    int t;

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
