class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // At the end majority element count will always be +ve as it appears move than n/2.
        // This algo. is called Moore's Algorithm
        int candidate = 0;
        int count = 0;
        for (int value:nums) {
            if (count == 0) {
                candidate = value;
            }
            if (candidate == value) {
                count++;
            }
            else {
                count--;
            }
        }
        return candidate;

        // If it is not given that there definitely exists a number > n/2 times frequency, in that case return -1
        // int count = 0;
        // for (int value:nums) {
        //     if (value == candidate) {
        //         count++;
        //     }
        // }
        // if (count > n/2) {
        //     return candidate;
        // }
        // else return -1;
    }
};