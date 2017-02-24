class Solution {
public:
    string intToRoman(int num) {
        string result;
        int num_table[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman_table[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int i = 0;
        while (num > 0) {
            for (; i < 13; i++) {
                if (num >= num_table[i]) {
                    break;
                }
            }
            num -= num_table[i];
            result += roman_table[i];
        }
        return result;
    }
};