class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string& word, int index, int i, int j) {
        if (index == word.length()) {
            return true;
        }

        int m = board.size();
        int n = board[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = ' '; 

        bool found = (backtrack(board, word, index + 1, i + 1, j) ||
                    backtrack(board, word, index + 1, i - 1, j) ||
                    backtrack(board, word, index + 1, i, j + 1) ||
                    backtrack(board, word, index + 1, i, j - 1));

        board[i][j] = temp; 

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && backtrack(board, word, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};