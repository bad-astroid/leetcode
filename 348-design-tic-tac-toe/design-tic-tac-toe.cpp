class TicTacToe {
public:
    vector<int> cols, rows;
    int dia1, dia2, N;
    TicTacToe(int n) {
        cols = vector<int> (n);
        rows = vector<int> (n);
        dia1 = 0;
        dia2 = 0;
        N = n;
    }
    void updateValues(int row, int col, int player) {
        if(row == col) {
            dia1 += player;
        }
        if(row + col == N - 1) {
            dia2 += player;
        }
        cols[col] += player;
        rows[row] += player;
    }
    bool checkWinner(int row, int col) {
        return abs(dia1) == N
            || abs(dia2) == N
            || abs(cols[col]) == N
            || abs(rows[row]) == N;
    }
    int move(int row, int col, int player) {
        updateValues(row, col, (player == 1) ? 1 : -1);

        if(checkWinner(row, col)) {
            return player;
        }

        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */