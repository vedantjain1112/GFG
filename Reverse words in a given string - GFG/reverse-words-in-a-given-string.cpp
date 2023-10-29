//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:

    string reverseWords(string S) {
        stack<string> wordsStack;
        stringstream ss(S);
        string word;
    
        while (getline(ss, word, '.')) {
            wordsStack.push(word);
        }
    
        string reversedString;
        while (!wordsStack.empty()) {
            reversedString += wordsStack.top();
            wordsStack.pop();
    
            if (!wordsStack.empty()) {
                reversedString += '.';
            }
        }
    
        return reversedString;
    }

};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends