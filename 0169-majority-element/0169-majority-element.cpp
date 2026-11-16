class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = INT_MIN;
        int count = 0;
        for (int val : nums) {
            // if (vl == candidate) {
                // count++;
            // } else if (count == 0) {
                // candidate = val;
            // } else {
                // count--;
            // }
            if (count == 0) {
                candidate = val;
                count = 1;
            } else if(val == candidate) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }
};