//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
       int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
    
        queue<pair<int, int>> rottenQueue;
        int freshOranges = 0;
    

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    rottenQueue.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }
    
        int time = 0;
        vector<int> dirX = {0, 0, 1, -1};
        vector<int> dirY = {1, -1, 0, 0};
    
        while (!rottenQueue.empty() && freshOranges > 0) {
            int size = rottenQueue.size();
    
            for (int i = 0; i < size; ++i) {
                int x = rottenQueue.front().first;
                int y = rottenQueue.front().second;
                rottenQueue.pop();
    
                for (int d = 0; d < 4; ++d) {
                    int newX = x + dirX[d];
                    int newY = y + dirY[d];
    
                    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        rottenQueue.push({newX, newY});
                        freshOranges--;
                    }
                }
            }
    
            time++;
        }
    
        return (freshOranges == 0) ? time : -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends