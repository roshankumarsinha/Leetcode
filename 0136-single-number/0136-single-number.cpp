class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;  // Doing XOR of any number with 0 gives same number/
        for (int i=0;i<nums.size();i++) {
            result = result ^ nums[i];  // Doing XOR with same number will give 0
        }
        return result;
    }
};