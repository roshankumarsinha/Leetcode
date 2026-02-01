class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>
            prefixCount; // {prefixSum: frequency (how many times this prefixSum
                         // has occurred)}
        prefixCount[0] = 1; // Empty prefix with sum 0

        int prefixSum =
            0; // prefixSum = sum of all elements from start to current index
        int count = 0; // count = number of subarrays with sum = k

        for (int num : nums) {
            prefixSum += num; // Add current element to prefixSum

            // Check how many times (prefixSum - k) occurred
            int need = prefixSum - k;
            if (prefixCount.find(need) !=
                prefixCount.end()) { // We can also write as
                                     // prefixCount.count(need) > 0
                count += prefixCount[need];
            }

            // Add current prefixSum to map
            prefixCount[prefixSum]++;
        }

        return count;
    }
};