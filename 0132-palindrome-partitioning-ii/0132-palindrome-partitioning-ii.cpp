class Solution {
public:
  int minCut(string s) {
        int n = s.length();

        // Initialize a vector to store minimum cuts
        vector<int> minCuts(n, 0);

        // Initialize a 2D vector to store whether a substring is a palindrome
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        // Calculate palindrome information for all substrings
        for (int len = 1; len <= n; ++len) {
            for (int start = 0; start <= n - len; ++start) {
                int end = start + len - 1;
                if (s[start] == s[end] && (len <= 2 || isPalindrome[start + 1][end - 1])) {
                    isPalindrome[start][end] = true;
                }
            }
        }

        // Calculate minimum cuts using dynamic programming
        for (int end = 1; end < n; ++end) {
            int minCutValue = INT_MAX;
            for (int start = end; start >= 0; --start) {
                if (isPalindrome[start][end]) {
                    minCutValue = (start == 0) ? 0 : min(minCutValue, 1 + minCuts[start - 1]);
                }
            }
            minCuts[end] = minCutValue;
        }

        return minCuts[n - 1];
    }
};