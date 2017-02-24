class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        fun(result, nums, 0, vector<int>());
        return result;
    }

private:
    void fun(vector<vector<int>> &result, vector<int>& nums, int i, vector<int> temp) {
        if (i == nums.size()) {
            result.push_back(temp);
            return;
        }
        fun(result, nums, i + 1, temp);
        temp.push_back(nums[i]);
        fun(result, nums, i + 1, temp);
    }

};