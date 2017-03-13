class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> s;
        int res = 0;
        long long sum= 0;
        s.insert(0);
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res += std::distance(s.lower_bound(sum - upper), s.upper_bound(sum - lower));
            s.insert(sum);
        }
        return res;
    }
};