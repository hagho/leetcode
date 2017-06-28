class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int used1[9][9] = {0};
        int used2[9][9] = {0};
        int used3[9][9] = {0};
        if (board.empty()) {
            return false;
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;
                    if (used1[i][num] || used2[j][num] || used3[k][num]) {
                        return false;
                    }
                    used1[i][num] = 1;
                    used2[j][num] = 1;
                    used3[k][num] = 1;
                }
            }
        }
        return true;
    }
};