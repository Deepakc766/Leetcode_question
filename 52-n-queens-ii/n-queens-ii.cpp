class Solution {
public:
    bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
        
        for (int j = 0; j < col; ++j)
            if (board[row][j]) return false;

 
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
            if (board[i][j]) return false;


        for (int i = row, j = col; i < n && j >= 0; ++i, --j)
            if (board[i][j]) return false;

        return true;
    }

    void addSolution(const vector<vector<int>>& board, vector<vector<string>>& ans, int n) {
        vector<string> single;
        single.reserve(n);
        for (int i = 0; i < n; ++i) {
            string row;
            row.reserve(n);
            for (int j = 0; j < n; ++j)
                row.push_back(board[i][j] ? 'Q' : '.');
            single.push_back(row);
        }
        ans.push_back(single);
    }
  void solve(int col, vector<vector<string>>& ans, vector<vector<int>>& board, int n) {
        if (col == n) {
            addSolution(board, ans, n);
            return;
        }

        for (int row = 0; row < n; ++row) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 1;
                solve(col + 1, ans, board, n);
                board[row][col] = 0; // backtrack
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        if (n <= 0) return ans.size();
        vector<vector<int>> board(n, vector<int>(n, 0));
        solve(0, ans, board, n);
        return ans.size();
    }
};