class Solution {
public:
   int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }

        // Initialize variables to store profits after the first and second transactions
        int firstBuy = INT_MIN, firstSell = 0;
        int secondBuy = INT_MIN, secondSell = 0;

        for (int i = 0; i < n; ++i) {
            // Update the variables for the first transaction
            firstBuy = max(firstBuy, -prices[i]);
            firstSell = max(firstSell, firstBuy + prices[i]);

            // Update the variables for the second transaction
            secondBuy = max(secondBuy, firstSell - prices[i]);
            secondSell = max(secondSell, secondBuy + prices[i]);
        }

        // The final profit is the maximum of the two transaction profits
        return secondSell;
    }
};