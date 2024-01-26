class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // Define a 3D array to store the number of paths for each cell and move.
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        int MOD = 1000000007;
        
        // Initialize the starting position.
        dp[0][startRow][startColumn] = 1;
        
        int count = 0;
        
        // Directions for moving: up, down, left, right.
        vector<int> dirs = {-1, 0, 1, 0, -1};
        
        // Iterate over the number of moves.
        for (int move = 1; move <= maxMove; ++move) {
            for (int row = 0; row < m; ++row) {
                for (int col = 0; col < n; ++col) {
                    // Iterate over all possible directions.
                    for (int k = 0; k < 4; ++k) {
                        int newRow = row + dirs[k];
                        int newCol = col + dirs[k + 1];
                        
                        // Check if the new position is within the boundary.
                        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                            // If the ball moves out of the boundary, count the path.
                            if (dp[move - 1][row][col] > 0 && dp[move - 1][row][col] <= MOD - 1)
                                dp[move][newRow][newCol] = (dp[move][newRow][newCol] + dp[move - 1][row][col]) % MOD;
                        } else {
                            // If the ball moves out of the boundary, count the path.
                            if (dp[move - 1][row][col] > 0 && dp[move - 1][row][col] <= MOD - 1)
                                count = (count + dp[move - 1][row][col]) % MOD;
                        }
                    }
                }
            }
        }
        
        return count;
    }
};