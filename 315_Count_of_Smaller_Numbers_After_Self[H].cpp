class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        for (auto i = nums.end() -  1; i >= nums.begin(); i--) {
                int  ans = 0;
                for(auto j  =  i + 1; j < nums.end(); j++) {
                    if (*i > *j) {
                        j++;
                        ans++;
                    } else {
                        break;
                    }
                }
                res.insert(res.begin(), ans);
                sort(i, num.end());
        }
        return res;
    }
};