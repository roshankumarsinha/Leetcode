class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(); // Total number of cards
        int totalSum = 0;          // Total sum of all card scores

        // Calculate the total sum of all card scores
        for (int score : cardPoints) {
            totalSum += score;
        }

        // If k is equal to the number of cards, return the total sum
        if (k == n) {
            return totalSum;
        }

        int windowSize = n - k; // Size of the subarray to find with minimum sum
        int currentWindowSum = 0; // Current sum of the sliding window

        // Calculate the sum of the first window of size n-k
        for (int i = 0; i < windowSize; i++) {
            currentWindowSum += cardPoints[i];
        }

        int minWindowSum = currentWindowSum;

        // Slide the window across the array to find the minimum sum subarray of
        // size n-k
        for (int i = windowSize; i < n; i++) {
            currentWindowSum =
                currentWindowSum + cardPoints[i] -
                cardPoints[i -
                           windowSize]; // Update the window sum, adding the new
                                        // element and removing the old element
            minWindowSum = min(minWindowSum, currentWindowSum);
        }

        // The maximum score is total sum minus the minimum sum of the subarray
        // of size n-k
        return totalSum - minWindowSum;
    }
};