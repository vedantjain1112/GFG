//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
     const int MOD = 1000000007;

    int countFriendsPairings(int n) {
        if (n == 0 || n == 1 || n == 2) {
            return n;
        }
    
        vector<long long> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
    
        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] % MOD + (i - 1) * dp[i - 2] % MOD) % MOD;
        }
    
        return dp[n];
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends