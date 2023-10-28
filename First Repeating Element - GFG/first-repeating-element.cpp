//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution {
  public:
      int firstRepeated(int arr[], int n) {
        unordered_map<int, int> indexMap;
        int minIndex = INT_MAX;
    
        for (int i = 0; i < n; ++i) {
            if (indexMap.find(arr[i]) != indexMap.end()) {
                minIndex = min(minIndex, indexMap[arr[i]]);
            } else {
                indexMap[arr[i]] = i;
            }
        }
    
        if (minIndex == INT_MAX) {
            return -1; 
        } else {
            return minIndex + 1; 
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}

// } Driver Code Ends