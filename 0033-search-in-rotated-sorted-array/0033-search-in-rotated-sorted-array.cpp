class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = start + ((end - start) / 2);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[start] <= nums[mid]) { // One of the half is confirmed sorted, so here we are checking if Left-half is sorted or not
                if (target <= nums[mid] && target >= nums[start]) { // If Left part is sorted then perform Binary-Search there
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else { // else Right-half is sorted
                if (target >= nums[mid] && target <= nums[end]) { // If Right part is sorted then perform Binary-Search there
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};