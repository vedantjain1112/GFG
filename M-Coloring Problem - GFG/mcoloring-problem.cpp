//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
   bool isSafe(int node, int color, int N, bool graph[101][101], int colors[]) {
        for (int i = 0; i < N; i++) {
            if (graph[node][i] && colors[i] == color) {
                return false;
            }
        }
        return true;
    }

    bool graphColoringUtil(bool graph[101][101], int m, int N, int colors[], int node) {
        if (node == N) {
            return true;
        }
    
        for (int color = 1; color <= m; color++) {
            if (isSafe(node, color, N, graph, colors)) {
                colors[node] = color;
                if (graphColoringUtil(graph, m, N, colors, node + 1)) {
                    return true;
                }
                colors[node] = 0;
            }
        }
    
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        int colors[n];
        memset(colors, 0, sizeof(colors));
    
        if (graphColoringUtil(graph, m, n, colors, 0)) {
            return true;
        }
    
        return false;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends