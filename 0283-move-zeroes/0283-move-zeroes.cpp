class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroIndex = -1;
        int count = 0;
        // Here I'm movinf all non-zeros element to front and counting the
        // number of zeros
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0 && count == 0) {
                zeroIndex = i;
                count++;
            } else if (nums[i] == 0 && count > 0) {
                count++;
            } else if (nums[i] != 0 && zeroIndex >= 0) {
                nums[zeroIndex] = nums[i];
                zeroIndex++;
            }
        }
        // Filling rest of the array with 0
        if (count > 0) {
            for (int i = nums.size() - count; i < nums.size(); i++) {
                nums[i] = 0;
            }
        }
        // Note : This can be solved using 2 pointer as well, swap once zero is
        // find swap(zeroElement, nonZeroElement). Please refer solution section
    }
};