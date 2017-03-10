class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), -1));
        int ret = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                cout<<res[i][j]<<endl;
                if (res[i][j] == -1) {
                    res[i][j] =1 + mymax(dp(matrix, res, i + 1, j, matrix[i][j]), dp(matrix, res, i - 1, j, matrix[i][j]), dp(matrix, res, i, j + 1, matrix[i][j]), dp(matrix, res, i, j -  1, matrix[i][j]));
                }
                cout<<res[i][j]<<endl;
                if (res[i][j] > ret) {
                    ret = res[i][j];
                }
            }
        }
        return ret;
    }

private:
    int mymax(int a, int b, int c, int d) {
        int temp = a;
        if (b > temp) {
            temp = b;
        }
        if (c > temp) {
            temp = c;
        }
        if (d > temp) {
            temp = d;
        }
        return temp;
    }
    
    int dp(vector<vector<int>>& matrix, vector<vector<int>>& res, int i, int j, int judge) {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()) {
            return 0;
        }
        //cout<<judge << " aaaaa"<< matrix[i][j]<<endl;
        if (judge >= matrix[i][j]) {
            return 0;
        }
        if (res[i][j] != -1) {
            return res[i][j];
        }
        if (res[i][j] == -1) {
            res[i][j] = 1 + mymax(dp(matrix, res, i + 1, j, matrix[i][j]), dp(matrix, res, i - 1, j, matrix[i][j]), dp(matrix, res, i, j + 1, matrix[i][j]), dp(matrix, res, i, j -  1, matrix[i][j]));
        }
        return res[i][j];

    }
    
};