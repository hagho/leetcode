class Solution {
public:
    bool isMatch(string s, string p) {
        return myMatch(s, s.size() - 1, p, p.size() - 1);
    }
private:
    bool myMatch(string s, int i, string p, int j) {
        if (j == -1) {
            if (i == -1) {
                return true;
            } else {
                return false;
            }
        }
        if (p[j] == '*') {
            if (i > -1 && (p[j - 1] == s[i] || p[j - 1] == '.')) {
                if (myMatch(s, i - 1,p, j)) {
                    return true;
                }
            }
            return myMatch(s, i, p, j - 2);

        } else if (p[j] == '.' || p[j] == s[i]) {
            return myMatch(s, i - 1, p, j - 1);
        } else {
            return false;
        }
    }

};