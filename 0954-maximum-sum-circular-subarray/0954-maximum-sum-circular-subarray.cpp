class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // For logic watch this video => https://youtu.be/CGFohM-BkWM?si=96Wf2jGdl0Nn_qmm

        int total_sum = 0;  // To store total sum of array.
        int curr_sum1 = 0;  // To store currentSum for maximum Sum SubArray
        int curr_sum2 = 0;  // To store cuurentSum for minimum Sum SubArray
        int mxsum_subary = INT_MIN;  // Initialize with -ve Infinity
        int minsum_subary = INT_MAX;   // Initialize with +ve Infinity

        // Below code is normal Kadane's with Maximum sum in subArray
        for(auto value:nums)
        {
            total_sum = total_sum + value;
            curr_sum1 = curr_sum1 + value;
            mxsum_subary = max(mxsum_subary, curr_sum1);
            if (curr_sum1 < 0) {
                curr_sum1 = 0;
            }
        }
        cout << "mxsum_subary " << mxsum_subary <<endl;

        // Below code is Kadane's with Minimum sum in subArray
        for(auto value:nums)
        {
            curr_sum2 = curr_sum2 + value;
            minsum_subary = min(curr_sum2, minsum_subary);
            if (curr_sum2 > 0) {
                curr_sum2 = 0;
            }
        }
        cout << "minsum_subary " << minsum_subary <<endl;
        cout << "total_sum " << total_sum << endl;

        return (total_sum == minsum_subary) ?  // If array has all -ve num than 9total_sum - minsum_subary) will give result 0, so for that edge case return normal Kadane's maxsum_subary
        mxsum_subary : 
        max(mxsum_subary,total_sum - minsum_subary);  // Otherwise max(Normal Kadane if max sum is not in circular subarray, (total_sum - minsum_subary if maximum sum occurs in circular subarray)).
        // Why (total_sum - minsum_subary) ? :
        // => (some prefix + some suffix), which is same as (total_sum_array - sum_of_some_subarray)
        // => To maximise (total_sum_array - sum_of_some_subarray) we have to minimise(sum_of_some_subarray)
    }
};