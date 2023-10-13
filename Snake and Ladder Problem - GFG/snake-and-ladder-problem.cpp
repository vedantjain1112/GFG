//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
      int minThrow(int N, int arr[]) {
        unordered_map<int, int> snakeLadderMap;
    
        for (int i = 0; i < 2 * N; i += 2) {
            snakeLadderMap[arr[i]] = arr[i + 1];
        }
    
  
        queue<pair<int, int>> q;
        q.push({1, 0}); 
    
       
        bool visited[31] = {false};
        visited[1] = true;
    
        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
    
            int currentPos = current.first;
            int throwCount = current.second;
    
            for (int i = 1; i <= 6; i++) {
                int nextPos = currentPos + i;
    
             
                if (nextPos == 30) {
                    return throwCount + 1;
                }
    
                if (nextPos <= 30) {
                
                    if (snakeLadderMap.find(nextPos) != snakeLadderMap.end()) {
                        nextPos = snakeLadderMap[nextPos];
                    }
    
                    
                    if (!visited[nextPos]) {
                        q.push({nextPos, throwCount + 1});
                        visited[nextPos] = true;
                    }
                }
            }
        }
    
        return -1; // If destination is not reachable
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends