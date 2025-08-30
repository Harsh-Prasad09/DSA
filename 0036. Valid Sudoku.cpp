class Solution {
public:
    bool rowValid(vector<vector<char>>& board) {
        for (int i = 0; i<9; i++) {
            for (int j = 0; j<9; j++) {
                if (board[i][j] != '.') {
                    char ch = board[i][j];

                    for (int k = 0; k<9; k++) {
                        if (k == j) continue;
                        if (board[i][k] == ch) return false;
                    }
                }
            }
        }

        return true;
    }

    bool colValid(vector<vector<char>>& board) {
        for (int i = 0; i<9; i++) {
            for (int j = 0; j<9; j++) {
                if (board[i][j] != '.') {
                    char ch = board[i][j];

                    for (int k = 0; k<9; k++) {
                        if (k == i) continue;
                        if (board[k][j] == ch) return false;
                    }
                }
            }
        }

        return true;
    }

    bool subMatrixValid(vector<vector<char>>& board) {
        for (int i = 0; i<9; i+=3) {
            for (int j = 0; j<9; j+=3) {
                vector<bool> vis(10, false);

                for (int x = i; x<i+3; x++) {
                    for (int y = j; y<j+3; y++) {
                        if (board[x][y] != '.') {
                            int num = board[x][y] - '0';
                            if (vis[num]) return false;
                            else vis[num] = true;
                        }
                    }
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return rowValid(board) && colValid(board) && subMatrixValid(board);
    }
};
