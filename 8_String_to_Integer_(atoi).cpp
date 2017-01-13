    class Solution {
public:
    int myAtoi(string str) {
        int base = 0;
        int i = 0;
        int sign = 1;
        while (str[i] == ' ') {
            i++;
        }
        if (str [i] == '+' || str[i] == '-') {
            sign = 1 - 2 * (str[i++] == '-');
        }
        while (str[i] >= '0' && str[i] <= '9') {
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] > '7' && sign == 1) || (base == INT_MAX / 10 && str[i] > '8' && sign == -1)) {
                if (sign == 1) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            base = base * 10 + (str[i] - '0');
            i++;
        }
        return base * sign;
    }
};