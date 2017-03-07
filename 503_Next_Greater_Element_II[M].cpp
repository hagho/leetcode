class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            res.push_back(fun(nums[i], i, nums));
        }
        return res;
    }

private:
    int fun(int n, int i, vector<int>& nums) {
        bool flag = false;
        int temp = i + 1;
        while (temp != i) {
            if (nums[temp] > n) {
                return nums[temp];

            } else {
                temp++;
                if(temp == nums.size()){
                    temp = 0;
                }
            }
        }
        return -1;
    }
};