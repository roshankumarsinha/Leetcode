class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minimumBuyPrice = INT_MAX;
        for (int i=0;i<prices.size();i++) {
            if (prices[i] < minimumBuyPrice) {
                minimumBuyPrice = prices[i];
            }
            else {
                profit = max(profit, prices[i] - minimumBuyPrice);
            }
        }
        return profit;
    }
};