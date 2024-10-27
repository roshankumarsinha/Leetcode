class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit = profit + (prices[i] - prices[i - 1]);
            }
        }

        return profit;
    }
};

// Watch the first solution for C++.
// Divide the array into smaller parts, and for each increasing subArray just add all the profits, that will become maxProfit