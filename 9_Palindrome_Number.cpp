class Solution {
public:
    bool isPalindrome(int x) {
        long long r = 0;
        long long xx = x;
        if (x < 0) {
            return false;
        }
        while (xx != 0) {
            r = r * 10 + xx % 10;
            xx /= 10;
        }
        long long xxx = x;
        return  xxx == r;
    }
};