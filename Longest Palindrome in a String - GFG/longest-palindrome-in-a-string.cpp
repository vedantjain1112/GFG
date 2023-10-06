//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   string expandAroundCenter(string s, int left, int right) {
    int n = s.length();

    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }

        return s.substr(left + 1, right - left - 1);
    }

    string longestPalin(string S) {
        int n = S.length();
        if (n <= 1) {
            return S;
        }

        string longestPalindrome = "";

    for (int i = 0; i < n; ++i) {
 
        string palindromeOdd = expandAroundCenter(S, i, i);
        if (palindromeOdd.length() > longestPalindrome.length()) {
            longestPalindrome = palindromeOdd;
        }

        string palindromeEven = expandAroundCenter(S, i, i + 1);
        if (palindromeEven.length() > longestPalindrome.length()) {
            longestPalindrome = palindromeEven;
        }
    }

    return longestPalindrome;
}

};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends