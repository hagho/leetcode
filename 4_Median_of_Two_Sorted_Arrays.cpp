class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        int flag = !(size % 2);
        int p1 = 0;
        int p2 = 0;
        if (nums1.empty()) {
            return ( nums2[nums2.size() / 2] + nums2[nums2.size() / 2 - flag] ) / 2.0;
        }
        if (nums2.empty()) {
            return ( nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - flag] ) / 2.0;
        }
        vector<int> nums3;
        for (int i = 0; i < size / 2 + 1; i++) {
            if (p1 >= nums1.size()) {
                nums3.push_back(nums2[p2++]);
                continue;
            }
            if (p2 >= nums2.size()) {
                nums3.push_back(nums1[p1++]);
                continue;
            }
            if (nums1[p1] <= nums2[p2]) {
                nums3.push_back(nums1[p1]);
                p1++;

            }
            else {
                nums3.push_back(nums2[p2]);
                p2++;
            }
        }
        int p3 = nums3.size();
        return ( nums3[p3 - 1] + nums3[p3 - 1 - flag] ) / 2.0;
    }
};