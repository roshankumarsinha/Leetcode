class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = INT_MIN;
        int count = 0;
        for (int val : nums) {
            if (val == candidate) {
                count++;
            } else if (count == 0) {
                candidate = val;
            } else {
                count--;
            }
        }
        return candidate;
    }
};