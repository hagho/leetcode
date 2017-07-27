class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size(), false);
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < wordDict.size(); j++) {
                if (i + 1 - (int)wordDict[j].size() < 0) {
                    continue;
                }
                if (wordDict[j] == s.substr(i + 1 - wordDict[j].size(), wordDict[j].size()) && ( i - wordDict[j].size() == -1 || dp[i - wordDict[j].size()] )) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size() - 1];
    }
};