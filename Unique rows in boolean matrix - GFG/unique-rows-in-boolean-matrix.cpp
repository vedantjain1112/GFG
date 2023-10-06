//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    public:
    // #define MAX 1000
   vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col) {
    vector<vector<int>> result;
    unordered_set<string> uniqueRows;

    for (int i = 0; i < row; ++i) {
        string rowStr = "";
        vector<int> currentRow;

        for (int j = 0; j < col; ++j) {
            rowStr += to_string(M[i][j]);
            currentRow.push_back(M[i][j]);
        }

        if (uniqueRows.find(rowStr) == uniqueRows.end()) {
            result.push_back(currentRow);
            uniqueRows.insert(rowStr);
        }
    }

    return result;
}
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends