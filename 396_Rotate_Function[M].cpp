class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.size() == 0) {
            return 0;
        }        
        int res = INT_MIN;
        for (int i = 0; i < A.size(); i++) {
            res = max(res, fun(i, A));
        }
        return res;
    }
    int fun(int idx, vector<int>& A) {
        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            res += i * A[idx];
            idx++;
            if (idx == A.size()) {
                idx = 0;
            }
        }
        return res;
    }
};