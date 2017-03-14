class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size() + nums2.size());
        set<int> a(nums1.begin(),nums1.end());
        set<int> b(nums2.begin(),nums2.end());
        auto i = set_intersection(a.begin(), a.end(), b.begin(), b.end() , res.begin());
        res.resize(i - res.begin());
        return res;
    }
};