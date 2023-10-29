//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
     vector<long long> printFibb(int n) {
        vector<long long> result;
    
        if (n <= 0) {
            return result; 
        }
    
        if (n >= 1) {
            result.push_back(1);
        }
    
        if (n >= 2) {
            result.push_back(1);
        }
    
        for (int i = 2; i < n; i++) {
            long long nextFib = result[i - 1] + result[i - 2];
            result.push_back(nextFib);
        }
    
        return result;
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends