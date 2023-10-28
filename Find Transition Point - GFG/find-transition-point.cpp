//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


    int transitionPoint(int arr[], int n) {
        int low = 0, high = n - 1;
    
        while (low <= high) {
            int mid = low + (high - low) / 2;
    
            if (arr[mid] == 1 && (mid == 0 || arr[mid - 1] == 0)) {
                return mid;
            }
    
    
            if (arr[mid] == 0) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    
        return -1; 
    }