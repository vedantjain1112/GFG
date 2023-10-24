//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
   bool isValid(string s) {
        int num = stoi(s);
        return to_string(num) == s && num >= 0 && num <= 255;
    }

    void generateIPs(string s, int start, vector<string>& current, vector<string>& result) {
        if (start == s.length() && current.size() == 4) {
            result.push_back(current[0] + "." + current[1] + "." + current[2] + "." + current[3]);
            return;
        }
    
        for (int i = start; i < s.length(); i++) {
            string segment = s.substr(start, i - start + 1);
    
            if (isValid(segment)) {
                current.push_back(segment);
                generateIPs(s, i + 1, current, result);
                current.pop_back();
            } else {
                break;  
            }
        }
    }
    
    vector<string> genIp(string &s) {
        vector<string> result;
        if (s.length() < 4 || s.length() > 12) {
            result.push_back("-1");
            return result;
        }
    
        vector<string> current;
        generateIPs(s, 0, current, result);
    
        return result;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends