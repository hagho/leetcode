class Solution {
public:
    vector<int> KMP(string target) {
        vector<int> match(target.size(), -1);
        int j = -1;
        for (int i = 1; i < target.size(); i++) {
            while (j >= 0 && target[i] != target[j + 1]) {
                j = match[j];
            }
            if (target[i] == target[j + 1]) {
                j++;
            }
            match[i] = j;
        }
        return match;
    }
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        int m = haystack.size();
        int n = needle.size();
        int j = -1;
        vector<int> match = KMP(needle);
        for (int i = 0;i < m; i++) {
            while (j >= 0 && haystack[i] != needle[j + 1]) {
                j = match[j];
            }
            if (haystack[i] == needle[j + 1]) {
                j++;
            }
            if (j == n- 1) {
                return i - n + 1;
            }
        }
        return -1;
    }
};