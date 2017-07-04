class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
        return dp(table, 1, n);
    }
    int dp(vector<vector<int>>& table, int st, int ed) {
        if (st >= ed) {
            return 0;
        }
        if (table[st][ed] != 0) {
            return table[st][ed];
        }
        int res = INT_MAX;
        for (int i = st; i <= ed; i++) {
            int tmp = i + max(dp(table, st, i - 1), dp(table, i + 1, ed));
            res = min(res, tmp);
        }
        table[st][ed] = res;
        return table[st][ed];
    }
};