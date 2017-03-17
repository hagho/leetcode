class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }
        for (int i =0; i < board.size(); i++) {
            dfs(i, 0, board);
            dfs(i, board[0].size() - 1, board);
        }
        for (int j =0; j < board[0].size(); j++) {
            dfs(0, j, board);
            dfs(board.size() - 1, j, board);
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0;j < board[0].size(); j++) {
                if (board[i][j] == '*') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        return;

    }
private:
    void dfs(int i, int j, vector<vector<char>>& board) {
        if (board[i][j] != 'O') {
            return;
        } 
        board[i][j] = '*';
        if (i + 1 < board.size() - 1) {
            dfs(i + 1, j ,board);
        }
        if (i - 1 > 0) {
            dfs(i - 1, j ,board);
        }
        if (j + 1 < board[0].size() - 1) {
            dfs(i, j + 1,board);
        }
        if (j - 1 > 0) {
            dfs(i, j - 1,board);
        }
    }
};