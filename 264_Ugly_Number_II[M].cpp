class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        vector<int> dp(n + 1);
        dp[1] = 1;
        int a = 1;
        int b = 1;
        int c = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[a] * 2, min(dp[b] * 3, dp[c] * 5));
            if (dp[i] == dp[a] * 2) {
                a++;
            }
            if (dp[i] == dp[b] * 3) {
                b++;
            }
            if (dp[i] == dp[c] * 5) {
                c++;
            }
        }
        return dp[n];
    }
};