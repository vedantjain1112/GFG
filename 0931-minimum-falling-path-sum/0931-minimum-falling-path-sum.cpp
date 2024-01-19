class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        
        // Iterate from the second last row to the first row
        for (int row = n - 2; row >= 0; --row) {
            for (int col = 0; col < n; ++col) {
                // Update the current element with the minimum falling path sum
                matrix[row][col] += std::min({ 
                    col > 0 ? matrix[row + 1][col - 1] : matrix[row + 1][col],
                    matrix[row + 1][col],
                    col < n - 1 ? matrix[row + 1][col + 1] : matrix[row + 1][col]
                });
            }
        }
        
        // Find the minimum value in the first row, which represents the minimum falling path sum
        return *std::min_element(matrix[0].begin(), matrix[0].end());
    }
};