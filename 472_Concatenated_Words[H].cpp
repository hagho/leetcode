class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        set<string> s(words.begin(), words.end());
        vector<string> res;
        for (int i = 0; i < words.size(); i++) {
            int n = words[i].size();
            vector<int> dp(n + 1);
            dp[0] = 1;
            for (int j = 0; j < n; j++) {
                if (dp[j] == 0) {
                    continue;
                }
                for(int k = j + 1; k <= n; k++) { 
                    if (k - j < n && s.count(words[i].substr(j, k - j))) {
                        dp[k] = 1;
                    }
                }
                if (dp[n]) {
                    res.push_back(words[i]);
                    break;
                }
            } 
        }
        return res;
    }
};