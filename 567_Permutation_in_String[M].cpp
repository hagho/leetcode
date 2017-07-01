class Solution {
public:

/*
    bool checkInclusion(string s1, string s2) {
        for (int i = 0; i < s2.size(); i++) {
            multi_set<int> s(s1.begin(), s1.end());
            int j = i + 1;
            while (s.find(s2[i]) != s.end()) {
                if (j - i == s1.size()) {
                    return true;
                }
                s.erase(s2[i]);
                j++;
            }
        }
        return false;
    }
*/
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt(256, 0);
        for (int i = 0; i < s1.size(); i++) {
            cnt[s1[i]]++;
        }
        int len = s1.size();
        for (int i = 0, j = 0; j < s2.size(); j++) {
            if (cnt[s2[j]]-- > 0) {
                len--;
            }
            while (len == 0) {
                if (j - i + 1 == s1.size()) {
                    return true;
                } 
                if (++cnt[s2[i++]] > 0) {
                    len++;
                }
            }
        }
        return false;
    }
};