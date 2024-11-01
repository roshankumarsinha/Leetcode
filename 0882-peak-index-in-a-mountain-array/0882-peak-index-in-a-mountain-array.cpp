class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // We have start as 1 and end as arr.size() - 2, because it's given
        // there will always be a mountain and since to be a mountain at-least 3
        // element in needed in array, and to avoid mid + 1 & mid -1 issue we
        // are pretty sure that start and end can't be our peak element.
        int start = 1;
        int end = arr.size() - 2;
        while (start <= end) {
            int mid = start + ((end - start) / 2);
            if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
                return mid;
            } else if (arr[mid] > arr[mid - 1]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};