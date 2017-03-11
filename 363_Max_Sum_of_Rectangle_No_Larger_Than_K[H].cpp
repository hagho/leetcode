class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if (n == 0) {
            return 0;
        }
        int m =matrix[0].size();
        int ans = INT_MIN;
        set<int> st;
        set<int>::iterator it;
        for (int i = 0; i < m; i++) {
            vector<int> sum(n, 0);
            for (int j = i; j < m; j++) {
                int curSum = 0;
                int curMax = INT_MIN;
                st.clear();
                st.insert(0);
                for (int row = 0; row < n; row++) {
                    sum[row] += matrix[row][j];
                    curSum += sum[row];
                    it = st.lower_bound(curSum - k);
                    if (it != st.end()) {
                        curMax = max(curMax, curSum - *it);
                    }
                    st.insert(curSum);
                }
                ans = max(ans,curMax);
            }
        }
        return ans;
    }
};