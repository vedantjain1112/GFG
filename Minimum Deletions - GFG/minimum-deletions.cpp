//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
   int minimumNumberOfDeletions(string S) {
        int n = S.length();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
    
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
    
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (S[i] == S[j] && len == 2) {
                    dp[i][j] = 2;
                } else if (S[i] == S[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        return n - dp[0][n - 1];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends