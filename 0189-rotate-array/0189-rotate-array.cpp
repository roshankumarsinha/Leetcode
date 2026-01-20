class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int correct_k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + correct_k);
        reverse(nums.begin() + correct_k, nums.end());
    }
};