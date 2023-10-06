//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        unordered_set<char> patternSet(patt.begin(), patt.end());
    
        int minIndex = INT_MAX;
    
        for (int i = 0; i < str.length(); ++i) {
            if (patternSet.find(str[i]) != patternSet.end()) {
                minIndex = min(minIndex, i);
            }
        }
    
        return (minIndex == INT_MAX) ? -1 : minIndex;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        string str;
        string patt;
        cin>>str;
        cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    }
	return 0;
}

// } Driver Code Ends