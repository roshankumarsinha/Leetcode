class Solution {
public:
    int countSubarraysWithSumAtMostGoal(const vector<int>& nums, int goal) {
        // Handle edge case where goal is negative
        // This edge case can occur when we have goal 0, but next time we call
        // with goal - 1 which is -1. Since array contains only 0s and 1s, no
        // subarray can have negative sum.
        if (goal < 0)
            return 0; // No subarrays possible with negative sum

        int left = 0;       // Left pointer of the sliding window
        int currentSum = 0; // Current sum of the window
        int count = 0;      // Count of subarrays with sum <= goal

        for (int right = 0; right < nums.size(); right++) {
            currentSum =
                currentSum +
                nums[right]; // Expand the window by adding the right element

            // Shrink the window from the left if the current sum exceeds the
            // goal We keep moving left pointer to right until currentSum <=
            // goal
            while (currentSum > goal && left <= right) {
                currentSum =
                    currentSum -
                    nums[left]; // Remove the left element from current sum
                left++;         // Move the left pointer to the right
            }

            // All subarrays ending at 'right' with sum <= goal
            // The number of such subarrays is length of the current window,
            // because any subarray that starts from index 'left' to 'right'
            // will have sum <= goal
            count =
                count +
                (right - left +
                 1); // right - left + 1 is the size of the current valid window
        }

        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int goal = k;
        vector<int> num;
        for (int number : nums) {
            if (number % 2 == 0) {
                num.push_back(0);
            } else {
                num.push_back(1);
            }
        }
        return countSubarraysWithSumAtMostGoal(num, goal) -
               countSubarraysWithSumAtMostGoal(num, goal - 1);
    }
};