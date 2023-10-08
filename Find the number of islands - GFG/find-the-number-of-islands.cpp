//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

      int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0; 
        }

        int numIslands = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    ++numIslands;
                    dfs(grid, i, j);
                }
            }
        }

        return numIslands;
    }

    private:
        void dfs(vector<vector<char>>& grid, int row, int col) {
            int rows = grid.size();
            int cols = grid[0].size();
    
    
            if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == '0') {
                return;
            }
    
         
            grid[row][col] = '0';
    
          
            dfs(grid, row - 1, col);
            dfs(grid, row + 1, col); 
            dfs(grid, row, col - 1); 
            dfs(grid, row, col + 1); 
            dfs(grid, row - 1, col - 1); 
            dfs(grid, row - 1, col + 1); 
            dfs(grid, row + 1, col - 1); 
            dfs(grid, row + 1, col + 1); 
        }

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends