//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
     bool isCyclicUtil(int node, vector<int>& visited, vector<int>& recStack, vector<int> adj[]) {
        visited[node] = 1;
        recStack[node] = 1;
    
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (isCyclicUtil(neighbor, visited, recStack, adj))
                    return true;
            } else if (recStack[neighbor]) {
                return true;
            }
        }
    
        recStack[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        vector<int> recStack(V, 0);
    
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCyclicUtil(i, visited, recStack, adj))
                    return true;
            }
        }
    
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends