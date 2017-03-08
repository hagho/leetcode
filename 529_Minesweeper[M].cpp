class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (click.empty()) {
            return board;
        }
        int a = click[0];
        int b = click[1];
        if (board[a][b] == 'M') {
            board[a][b] = 'X';
            return board;
        }
        int temp = countBoard(board, click);
        if (temp == 0) {
            board[a][b] = 'B';
        } else {
            board[a][b] = to_string(temp)[0];
            return board;
        }
        queue<vector<int>> q;
        q.push(click);
        while (!q.empty()) {
            a = (q.front())[0];
            b = (q.front())[1];
            q.pop();
            int xx[] = {-1, 0, 1};
            int yy[] = {-1, 0, 1};
            for (int i = 0; i < 3; i++) {
                for (int j = 0;j < 3; j++) {
                    int aa = a + xx[i];
                    int bb = b + yy[j];
                if (aa < 0 || bb < 0 || aa >= board.size() || bb >= board[0].size()) {
                    continue;
                }
                if (board[aa][bb] == 'E') {
                    vector<int> t{aa, bb};
                    temp = countBoard(board, t);
                    if (temp == 0) {
                        board[aa][bb] = 'B';
                        q.push(vector<int>{aa,bb});
                    } else {
                        board[aa][bb] = to_string(temp)[0];
                    }
                }
                }
            }
        }
        return board;
    }

private:
    int countBoard(vector<vector<char>>& board, vector<int>& click) {
        int a = click[0];
        int b = click[1];
        int cnt = 0;
        int xx[] = {-1, 0, 1};
        int yy[] = {-1, 0, 1};
        for (int i = 0; i < 3; i++) {
            for (int j = 0;j < 3; j++) {
                int aa = a + xx[i];
                int bb = b + yy[j];
                if (aa < 0 || bb < 0 || aa >= board.size() || bb >= board[0].size()) {
                    continue;
                }
                if (board[aa][bb] == 'M') {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};