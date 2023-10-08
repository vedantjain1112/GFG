//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void findCombinations(vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result, int start) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
    
        for (int i = start; i < candidates.size() && target >= candidates[i]; i++) {
            current.push_back(candidates[i]);
            findCombinations(candidates, target - candidates[i], current, result, i);
            current.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& A, int B) {
        vector<vector<int>> result;
        vector<int> current;
    
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
    
        findCombinations(A, B, current, result, 0);
    
        return result;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends