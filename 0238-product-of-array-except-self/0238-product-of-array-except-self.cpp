class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> suffix(length, 1);
        vector<int> prefix(length, 1);
        vector<int> ans(length, 1);
        
        // First calculate Prefix array excluding that element
        for (int i = 1; i < length; i++) {  
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Then calculate Suffix array excluding that element
        for (int i = length - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // Calculate ans array which is (prefix * suffix) this will exclude that element
        for (int i = 0; i < length; i++) {
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;

        // We can calculate it using single array :-
        // for (int i = 1; i < length; i++) {  // This is same as calculating prefix first
        //     ans[i] = ans[i - 1] * nums[i - 1];
        // }
        // int suffixValue = 1;
        // for (int i = length - 2; i >= 0; i--) {
        //     suffixValue = suffixValue * nums[i + 1]; // This is calculating suffix
        //     ans[i] = ans[i] * suffixValue; // This is same as calculating prefix * suffix
        // }
        // return ans;
    }
};