class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Iterate through the array
        for (int i = 0; i < n - 2; i++) { // We need at least 3 elements to form
                                          // a triplet, so we go up to n-2
            // Skip duplicate elements for the first element of the triplet
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            // Step 3: Use two-pointer technique to find the other two elements
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++; // We need a larger sum
                } else if (sum > 0) {
                    right--; // We need a smaller sum
                } else {
                    // Found a triplet
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Move both pointers inward
                    left++;
                    right--;

                    // Skip duplicate elements for the second element of the
                    // triplet
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    // Skip duplicate elements for the third element of the
                    // triplet
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }
        return result;
    }
};