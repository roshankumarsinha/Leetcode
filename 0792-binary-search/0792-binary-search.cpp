class Solution {
public:
    int search(vector<int>& nums, int target) {
        int startIndex = 0;
        int endIndex = nums.size() - 1;
        int result = -1;
        while (startIndex <= endIndex) {
            // Below is optimised way for calculating mid, as you can calculate mid = (start + end)/2 but we are calculating mid = start + ((end - start)/2) because what if start and end both become INT_MAX then it will go to overflow condition.
            int midIndex = startIndex + ((endIndex - startIndex) / 2);
            if (target < nums[midIndex]) {
                endIndex = midIndex - 1;
            } else if (target > nums[midIndex]) {
                startIndex = midIndex + 1;
            } else {
                result = midIndex;
                break;
            }
        }
        return result;
    }
};