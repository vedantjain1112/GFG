class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, std::numeric_limits<int>::max()));
        
        for (int j = 0; j < n; ++j) {
            dp[0][j] = grid[0][j];
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (j != k) {
                        dp[i][j] = std::min(dp[i][j], grid[i][j] + dp[i - 1][k]);
                    }
                }
            }
        }
        
        int minPathSum = std::numeric_limits<int>::max();
        for (int j = 0; j < n; ++j) {
            minPathSum = std::min(minPathSum, dp[n - 1][j]);
        }
        
        return minPathSum;
    }
};