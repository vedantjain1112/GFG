class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int count = 0;
        
        // Precompute prefix sum for each row
        for (int i = 0; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        
        // Iterate over all column pairs
        for (int col1 = 0; col1 < cols; ++col1) {
            for (int col2 = col1; col2 < cols; ++col2) {
                unordered_map<int, int> prefixSumCount;
                prefixSumCount[0] = 1;
                int currentSum = 0;
                
                // Iterate over all rows
                for (int row = 0; row < rows; ++row) {
                    int val = matrix[row][col2] - (col1 > 0 ? matrix[row][col1 - 1] : 0);
                    currentSum += val;
                    
                    // Check if there exists a prefix subarray that sums up to currentSum - target
                    count += prefixSumCount[currentSum - target];
                    
                    // Update the prefix sum count
                    prefixSumCount[currentSum]++;
                }
            }
        }
        
        return count;
    }
};