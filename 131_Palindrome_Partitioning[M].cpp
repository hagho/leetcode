class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        dfs(s, 0, temp, res);
        return res;
    }
    void dfs(string s, int idx, vector<string>& temp, vector<vector<string>>& res) {
        if (idx == s.size()) {
            res.push_back(temp);
            return ;
        }
        for (int i = idx; i < s.size(); i++) {
            int left = idx;
            int right = i;
            while (left < right && s[left] == s[right]) {
                left++;
                right--;
            }
            if (left >= right) {
                temp.push_back(s.substr(idx, i - idx + 1));
                dfs(s, i + 1, temp, res);
                temp.pop_back();
            }
        }
        return ;
    }
};