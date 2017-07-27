class Solution {
public:
    int integerReplacement(int n) {
        int res = 0;
        if (n == 1) {
            return res;
        }
        if (n == 2147483647) {
            return 32;
        }
        while (n != 1) {
            if (n == 3) {
                return res + 2;
            }
            if ( n & 1) {
                if (( n + 1 ) % 4 == 0) {
                    n++;
                } else {
                    n--;
                }

            } else {
                n /= 2;
            }
            res++;
        }
        return res;
    }
};