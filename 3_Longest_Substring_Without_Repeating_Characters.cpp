class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hashtable(255, -1);
        int i = -1;
        int result = 0; 
        for (int j = 0; j < s.size(); j++) {
            i = std::max(hashtable[s[j]], i);
            hashtable[s[j]] = j;
            result = std::max(result, j - i);
        }
        return result;
    }
};