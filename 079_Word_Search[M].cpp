class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (board.empty()) {
            if (word == "") {
                return true;
            } else {
                return false;
            }
        }
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false)); 
        for (int i = 0; i < m; i++) {
            for (int j =0; j < n; j++) {
                if ( dfs(board, i, j, word, 0, visited) ) {
                    return true;
                }
                visited[i][j] = false;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int pos,vector<vector<bool>>& visited) {
        /*
        cout<<i<<" "<<j<<" "<<word[pos]<<endl;
        for (int i = 0; i < board.size(); i++) {
            for (int j =0; j < board[0].size(); j++) {
                cout<<visited[i][j]<<' ';
            }
            cout<<endl;
        }
        */
        if (word[pos] != board[i][j]) {
            return false;
        }
        if (pos + 1 == word.size()) {
            return true;
        }
        vector<vector<int>> dd{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        visited[i][j] = true;
        for (auto d : dd) {
            int ii = i + d[0];
            int jj = j + d[1];
            if (ii < 0 || jj < 0 || ii > board.size() - 1 || jj > board[0].size() - 1) {
                continue;
            }
            if (!visited[ii][jj] && dfs(board, ii, jj, word, pos + 1, visited)) {
                return true;
            }
        }
         visited[i][j] = false;
        return false;
    }
};