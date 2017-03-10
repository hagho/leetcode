class Solution {
public:
    int reversePairs(vector<int>& nums) {
        /*
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > 2 * nums[j]) {
                    res++;
                }
            }
        }
        return res;
        */

        return sort_and_count(nums.begin(), nums.end());
    }

    int sort_and_count(vector<int>::iterator begin, vector<int>::iterator end) {
        if (end - begin <= 1) {
            return 0;
        }
        vector<int>::iterator mid = begin + ( end - begin ) / 2;
        int count = sort_and_count(begin, mid) + sort_and_count(mid, end);
        for (vector<int>::iterator i =begin, j = mid; i != mid; i++) {
            while (j != end && *i > 2L * *j) {
                j++;
            }
            count += j - mid;
        }
        inplace_merge(begin, mid, end);
        return count;
    }
};