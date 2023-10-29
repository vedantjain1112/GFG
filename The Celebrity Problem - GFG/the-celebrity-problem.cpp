//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    int celebrity(vector<vector<int> >& M, int n) {
        for (int i = 0; i < n; ++i) {
            bool isCelebrity = true;
    
            for (int j = 0; j < n; ++j) {
                if (i != j && (M[i][j] == 1 || M[j][i] == 0)) {
                    isCelebrity = false;
                    break;
                }
            }
    
            if (isCelebrity) {
                return i;
            }
        }
    
        return -1;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends