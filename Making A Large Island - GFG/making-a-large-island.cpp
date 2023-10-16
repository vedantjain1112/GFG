//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
      int largestIsland(vector<vector<int>>& grid) {
            int n = grid.size();
            int result = 0;
            int islandId = 2;
    
            unordered_map<int, int> islandSizes;
    
            function<int(int, int, int)> dfs = [&](int i, int j, int id) -> int {
                if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) {
                    return 0;
                }
    
                grid[i][j] = id;
                int size = 1;
    
                size += dfs(i + 1, j, id);
                size += dfs(i - 1, j, id);
                size += dfs(i, j + 1, id);
                size += dfs(i, j - 1, id);
    
                return size;
            };
    
       
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 1) {
                        int size = dfs(i, j, islandId);
                        islandSizes[islandId] = size;
                        result = max(result, size);
                        islandId++;
                    }
                }
            }
    
          
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 0) {
                        unordered_set<int> neighborIslands;
                        int potentialSize = 1;
    
                        
                        if (i > 0) neighborIslands.insert(grid[i - 1][j]);
                        if (i < n - 1) neighborIslands.insert(grid[i + 1][j]);
                        if (j > 0) neighborIslands.insert(grid[i][j - 1]);
                        if (j < n - 1) neighborIslands.insert(grid[i][j + 1]);
    
                        for (int id : neighborIslands) {
                            potentialSize += islandSizes[id];
                        }
    
                        result = max(result, potentialSize);
                    }
                }
            }

        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends