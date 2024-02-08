class Solution {
public:
    int numSquares(int n) {
        vector<int> perfectSquares;
        
        for (int i = 1; i * i <= n; ++i) {
            perfectSquares.push_back(i * i);
        }
        
        vector<int> dp(n + 1, INT_MAX);
        
        dp[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < perfectSquares.size(); ++j) {
                if (perfectSquares[j] > i) {
                    break;
                }
                dp[i] = std::min(dp[i], dp[i - perfectSquares[j]] + 1);
            }
        }
        
        return dp[n];
    }
};
