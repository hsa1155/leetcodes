class Solution {
public:
    int maxProfit(std::vector<int>& prices, int fee) {
        int n = prices.size();
        std::vector<int> dp(2, 0);
        dp[0] = 0;                // Max profit if not holding a stock
        dp[1] = -prices[0] - fee; // Max profit if holding a stock

        for (int i = 1; i < n; ++i) {
            dp[0] = std::max(dp[0], dp[1] + prices[i]);          // Max of not holding today or selling today
            dp[1] = std::max(dp[1], dp[0] - prices[i] - fee);    // Max of holding today or buying today
        }

        return dp[0]; // Return max profit when not holding any stock
    }
};