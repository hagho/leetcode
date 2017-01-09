class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> p(s.length() * 2  + 2, 1);
        string new_str(s.length() * 2 + 1, '#');
        int bound =0;
        int max_postion = 0;
        int id = 0;
        for (int i = 0; i < s.length(); i++) {
            new_str[2 * i + 1] =  s[i];
        }
        new_str = '$' + new_str;
        new_str = new_str + '\0';
        for (int i = 1; i < s.length() * 2  + 2; i++) {
            if (i < bound) {
                p[i] = std::min(bound-i, p[id * 2 - i]);
            }
            while (new_str[i - p[i]] == new_str[i + p[i]]) {
                p[i]++;
            }
            if (i + p[i] > bound) {
                bound = i + p[i];
                id =  i;
            }
            max_postion = p[max_postion] < p[i]? i : max_postion;
        }
        int len = p[max_postion] - 1;
        int start = (max_postion - p[max_postion]) / 2;
        return s.substr(start,len);
    }
};