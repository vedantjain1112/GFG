//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
   
        bool isInterleave(string A, string B, string C) {
        int n = A.length();
        int m = B.length();
    
    
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    
     
        if (n + m != C.length()) {
            return false;
        }
    
    
        dp[0][0] = true;
    
    
        for (int j = 1; j <= m; j++) {
            dp[0][j] = (B[j - 1] == C[j - 1]) && dp[0][j - 1];
        }
    
    
        for (int i = 1; i <= n; i++) {
            dp[i][0] = (A[i - 1] == C[i - 1]) && dp[i - 1][0];
        }
    
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = (A[i - 1] == C[i + j - 1] && dp[i - 1][j]) ||
                           (B[j - 1] == C[i + j - 1] && dp[i][j - 1]);
            }
        }
    
        return dp[n][m];
    }


};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends