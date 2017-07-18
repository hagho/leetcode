// class Solution {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
//         if (matrix.empty()) {
//             return vector<vector<int>>() ;
//         }
//         vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), -1));
//         vector<vector<bool>> m(matrix.size(), vector<bool>(matrix[0].size(), false));
//         for (int i = 0;i < matrix.size(); i++) {
//             for (int j = 0; j < matrix[0].size(); j++) {
//                 if (matrix[i][j] == 0) {
//                     res[i][j] = 0;
//                 }
//             }
//         }
//         for (int i = 0;i < res.size(); i++) {
//             for (int j = 0; j < res.size(); j++) {
//                 if (res[i][j] == -1) {
//                     dfs(i, j, res, m);
//                 }
//             }
//         }
//         return res;
//     }
//     int dfs(int x, int y, vector<vector<int>>& res, vector<vector<bool>>& m) {
//         if (x < 0 || y < 0 || x >= res.size() || y >= res[0].size()) {
//             return INT_MAX;
//         }
//         if (res[x][y] != -1) {
//             return res[x][y] + 1;
//         } else {
//             if (m[x][y]) {
//                 return INT_MAX;
//             }
//             m[x][y] = true;
//             int up = dfs(x + 1, y, res, m);
//             int down = dfs(x - 1, y, res, m);
//             int left = dfs(x, y - 1, res, m);
//             int right = dfs(x, y + 1, res, m);
//             res[x][y] = min(min(min(up, down), right),left);
//             return res[x][y];
//         }
//     }
// };

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return vector<vector<int>>();
        }
        vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] != 0) {
                    q.push(make_pair(i,j));
                }
            }
        }
        int step = 0;
        vector<int> xx{1, 0, -1, 0};
        vector<int> yy{0, 1, 0, -1};
        while (!q.empty()) {
            step++;
            queue<pair<int, int>> nqueue;
            vector<pair<int, int>> mqueue;
            vector<pair<int, int>> q2v;
            while (!q.empty()) {
                q2v.push_back(q.front());
                q.pop();
            }
            for (int i = 0;i < q2v.size(); i++) {
                int zero = 0;
                for (int j = 0; j < 4; j++) {
                    int nx = q2v[i].first + xx[j];
                    int ny = q2v[i].second + yy[j];
                    if (nx >= 0 && nx < res.size() && ny >= 0 && ny < res[0].size() && matrix[nx][ny] == 0) {
                        zero += 1;
                    }
                }
                if (zero) {
                    res[q2v[i].first][q2v[i].second] = step;
                    mqueue.push_back(q2v[i]);
                } else {
                    nqueue.push(q2v[i]);
                }
            }
            for (int i = 0; i < mqueue.size(); i++) {
                matrix[mqueue[i].first][mqueue[i].second] = 0;
            }
            q = nqueue;
        }
        return res;

    }
};