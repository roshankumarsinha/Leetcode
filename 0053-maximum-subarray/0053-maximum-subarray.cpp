class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSumSubarray = INT_MIN;  // maxSumSubarray will store the maximum sum of subArray. Initially it is initialised with INT_MIN which is min -ve value (-ve Infinity)
        int currSum = 0;  // currSum will store the current sum of subArray
        for (int value:nums) {
            currSum = currSum + value;
            maxSumSubarray = max(maxSumSubarray, currSum);
            if (currSum < 0) {  // Main logic is if current Sum becomes -ve after a big -ve number is added to it. Then that is the end of that subArray and start doing same process with next subArray.
                currSum = 0;
            }
        }
        return maxSumSubarray;
    }
};