class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        int j = 0;
        while (1) {
            if (strs.size() == 0 || j >= strs[0].size()) {
                return result;
            }
            char temp = strs[0][j];
            for (int i = 0; i < strs.size(); i++) {
                if (j >= strs[i].size() || strs[i][j] != temp) {
                    return result;
                }
            }
            result += temp;
            j++;
        }
    }
};