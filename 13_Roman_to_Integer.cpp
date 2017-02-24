#include <unordered_map>
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> table;
        init(table);
    //int num_table[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    //string roman_table[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            result += table[s[i]];
            if (i > 0 && table[s[i]] > table[s[i - 1]]) {
                result -= 2 * table[s[i - 1]];
            }
        }
        return result;
    }
private:
    void init(unordered_map<char, int> &table) {
        int num_table[] = {1000, 500, 100, 50, 10, 5, 1};
        char roman_table[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        for (int i = 0; i < 7; i++) {
            table[roman_table[i]] = num_table[i];
        }
    }
};