//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void buildGraph(vector<string>& dict, unordered_map<char, vector<char>>& graph, unordered_map<char, int>& inDegree) {
        for (string word : dict) {
            for (char c : word) {
                if (inDegree.find(c) == inDegree.end()) {
                    inDegree[c] = 0;
                    graph[c] = vector<char>();
                }
            }
        }
        
        for (int i = 1; i < dict.size(); i++) {
            string word1 = dict[i-1];
            string word2 = dict[i];
            
            int minLength = min(word1.length(), word2.length());
            for (int j = 0; j < minLength; j++) {
                char parent = word1[j];
                char child = word2[j];
                
                if (parent != child) {
                    graph[parent].push_back(child);
                    inDegree[child]++;
                    break;
                }
            }
        }
    }
    
    string findOrder(string dict[], int N, int K) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> inDegree;
        
        vector<string> words;
        for (int i = 0; i < N; i++) {
            words.push_back(dict[i]);
        }
        
        buildGraph(words, graph, inDegree);
        
        queue<char> q;
        for (auto entry : inDegree) {
            if (entry.second == 0) {
                q.push(entry.first);
            }
        }
        
        string result = "";
        while (!q.empty()) {
            char current = q.front();
            q.pop();
            result += current;
            
            for (char neighbor : graph[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        if (result.length() != inDegree.size()) {
            return "";
        }
        
        return result;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends