class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) {
            return false;
        }
        int sum = 0;;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 4 != 0) {
            return false;
        }
        //sort(nums.begin(), nums.end(), [](const int &l, const int &r){return l > r;});
        vector<int> sidelengths(4, 0);
        return dfs(sidelengths, nums, 0, sum / 4);
    }
    bool dfs(vector<int>& sidelengths, const vector<int>& matches, int index, const int target) {
        if (index == matches.size()) {
            return sidelengths[0] == sidelengths[1] && sidelengths[1] == sidelengths[2] && sidelengths[2] == sidelengths[3];
        }
        for (int i = 0 ; i < 4; i++) {
            if (sidelengths[i] + matches[index] > target) {
                continue;
            }
            int j = i;
            while (--j >= 0) {
                if (sidelengths[i] == sidelengths[j]) {
                    break;
                }
            }
            if (j != -1) {
                continue;
            }
            sidelengths[i] += matches[index];
            if (dfs(sidelengths, matches, index + 1, target)) {
                return true;
            }
            sidelengths[i] -= matches[index]; 
        }
        return false;
    }
};