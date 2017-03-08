class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), comp);
        for (int i = 0; i < d.size(); i++) {
            int j = 0;
            int k = 0;
            while (k < s.size() && j < d[i].size()) {
                if (s[k] == d[i][j]) {
                    k++;
                    j++;
                } else {
                    k++;
                }
            }
            if (j == d[i].size()) {
                return d[i];
            }
        }
        return "";
    }
private:
    static bool comp(string a, string b) {
        if (a.size() > b.size()) {
            return true;
        } else if (a.size() == b.size()) {
            return a < b;
        } else {
            return false;
        }
    }
};