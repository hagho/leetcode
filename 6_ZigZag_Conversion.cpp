#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string str[numRows];
        if (numRows == 1) {
            return s;
        }
        int flag = 1;
        for (int i = 0, j = 0; i  < s.length(); i++) {
            if (j == 0) {
                flag = 1;
            } 
            if (j == numRows - 1) {
                flag = -1;
            }
            str[j] += s[i];
            j += flag;
        }
        string result;
        for (int i = 0; i < numRows; i++) {
            result += str[i];
        }
        return result;
    }
};