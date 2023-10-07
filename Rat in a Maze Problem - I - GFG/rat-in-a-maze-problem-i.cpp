//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
  public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> paths; // To store the paths

        // Check if the source or destination is blocked
        if (m[0][0] == 0 || m[n - 1][n - 1] == 0) {
            return paths; // No path exists
        }

        string path; // Current path being explored
        findPaths(m, 0, 0, n, path, paths);

        // Sort the paths lexicographically
        sort(paths.begin(), paths.end());

        return paths;
    }

private:
    void findPaths(vector<vector<int>> &m, int i, int j, int n, string &path, vector<string> &paths) {
        if (i == n - 1 && j == n - 1) {
            paths.push_back(path);
            return;
        }

        m[i][j] = 0;

    
        if (i > 0 && m[i - 1][j] == 1) {
            path.push_back('U');
            findPaths(m, i - 1, j, n, path, paths);
            path.pop_back();
        }

        if (i < n - 1 && m[i + 1][j] == 1) {
            path.push_back('D');
            findPaths(m, i + 1, j, n, path, paths);
            path.pop_back(); 
        }

        if (j > 0 && m[i][j - 1] == 1) {
            path.push_back('L');
            findPaths(m, i, j - 1, n, path, paths);
            path.pop_back();
        }

        if (j < n - 1 && m[i][j + 1] == 1) {
            path.push_back('R');
            findPaths(m, i, j + 1, n, path, paths);
            path.pop_back();
        }

       
        m[i][j] = 1;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends