class Solution {
public:
    int divide(long dividend, long divisor) {
        if (divisor == 0 || dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int flag = (dividend >= 0) ^ (divisor >= 0);
        long long result = 0;
        long long did = abs(dividend);
        long long dis = abs(divisor);
        while (did >= dis) {
            long mul_dis = dis;
            int i = 0;
            while (did >= ( mul_dis << 1 )) {
                i++;
                mul_dis <<= 1;
            }
            did -= mul_dis;
            result += ( 1 << i );
        }
        return flag ? -result : result;
    }
};