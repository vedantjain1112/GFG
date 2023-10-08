//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
     bool findTriplets(int arr[], int n) {
        sort(arr, arr + n);
    
    
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            int target = -arr[i];
    
            while (left < right) {
                int currentSum = arr[left] + arr[right];
    
                if (currentSum == target) {
                    return true; // Triplet found
                } else if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    
        return false; 
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends