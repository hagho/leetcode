class Solution {
public:
    int reverse(int x) {
        long long temp = 0;
        while (x != 0) {
            temp *= 10;
            temp += x % 10;
            if (temp > INT_MAX || temp < INT_MIN) {
                return 0;
            }
            x /= 10;
        }
        return temp;
    }
};