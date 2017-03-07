class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < findNums.size(); i++) {
            res.push_back(fun(findNums[i], nums));
        }
        return res;
    }

private:
    int fun(int n, vector<int>& nums) {
        bool flag = false;
        for (int i = 0;i < nums.size(); i++) {
            if (nums[i] == n) {
                flag = true;
            }
            if (flag) {
                if (nums[i] > n) {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};