    #include <vector>
    #include <utility>
    using namespace std;
    class Solution {
    public:
        vector<pair<int, int> > pacificAtlantic(vector<vector<int> >& matrix) {
            int n = matrix.size();
            vector<pair<int, int> > res;
            if(n == 0) {
                return res;
            }
            int m = matrix[0].size();
            vector<vector<bool> > A(n, vector<bool>(m, false));
            vector<vector<bool> > B(n, vector<bool>(m, false));
            for (int i = 0; i < n; i++) {
                A[i][0] = true;
                B[i][m - 1] = true;
            }
            for (int j = 0; j < m; j++) {
                A[0][j] = true;
                B[n - 1][j] = true;
            }
            for (int i = 0; i < n; i++) {
                explore(A, matrix, i, 0);
                explore(B, matrix, i, m - 1);
            }
            for(int j = 0; j < m; j++) {
                explore(A, matrix, 0, j);
                explore(B, matrix, n - 1, j);
            }
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(A[i][j] && B[i][j]) {
                        res.push_back(pair<int, int>(i, j));
                    }
                }
            }
            return res;

        }
    private:
        void explore(vector<vector<bool>>& A, vector<vector<int>>& matrix, int i, int j) {
            A[i][j] = true;
            int dx[] = {-1, 0, 0, 1};
            int dy[] = {0, -1, 1, 0};
            for (int k = 0;k < 4; k++) {
                if (i + dx[k] < matrix.size() && i + dx[k] >= 0 &&  j + dy[k] < matrix[0].size() && 
                    j + dy[k] >= 0 &&  A[i + dx[k]][j + dy[k]] ==  false && 
                    matrix[i + dx[k]][j + dy[k]] >= matrix[i][j]) {
                    explore(A, matrix, i + dx[k], j + dy[k]);
                }
            }
        }
/*
        bool Pacific(vector<vector<int> >& matrix, vector<vector<bool> >& A, int n, int m, int i ,int j, int judge) {
            if (i < 0 || j < 0 || i >= n || j >= m) {
                return false;
            }
            if (A[i][j]) {
                return true;
            }
            if (i - 1 < 0  || j - 1 < 0) {
                A[i][j] = true;
                return true;
            }
            if (judge != 2 && !A[i][j]  && Pacific(matrix, A, n, m, i + 1, j, 1) && A[i][j] >= A[i + 1][j] ) {
                A[i][j] = true;
                return true;
            }
            if (judge != 1 && !A[i][j]  && Pacific(matrix, A, n, m, i - 1, j, 2) && A[i][j] >= A[i - 1][j] ) {
                A[i][j] = true;
                return true;
            }
            if (judge != 4 && !A[i][j]  && Pacific(matrix, A, n, m, i, j + 1, 3) && A[i][j] >= A[i][j + 1] ) {
                A[i][j] = true;
                return true;
            }
            if (judge != 3 && !A[i][j]  && Pacific(matrix, A, n, m, i, j - 1, 4) && A[i][j] >= A[i][j - 1] ) {
                A[i][j] = true;
                return true;
            }
            return A[i][j];
        }

        bool Atlantic(vector<vector<int> >& matrix, vector<vector<bool> >& A, int n, int m, int i ,int j,int judge) {
            if (i < 0 || j < 0 || i >= n || j >= m) {
                return false;
            }
            if (A[i][j]) {
                return true;
            }
            if (i + 1 >= n || j + 1 > = m) {
                A[i][j] = true;
                return true;
            }
            if (judge != 2 && !A[i][j]  && Pacific(matrix, A, n, m, i + 1, j, 1) && A[i][j] >= A[i + 1][j] ) {
                A[i][j] = true;
                return true;
            }
            if (judge != 1 && !A[i][j]  && Pacific(matrix, A, n, m, i - 1, j, 2) && A[i][j] >= A[i - 1][j] ) {
                A[i][j] = true;
                return true;
            }
            if (judge != 4 && !A[i][j]  && Pacific(matrix, A, n, m, i, j + 1, 3) && A[i][j] >= A[i][j + 1] ) {
                A[i][j] = true;
                return true;
            }
            if (judge != 3 && !A[i][j]  && Pacific(matrix, A, n, m, i, j - 1, 4) && A[i][j] >= A[i][j - 1] ) {
                A[i][j] = true;
                return true;
            }
            return A[i][j];
        }
*/
    };
