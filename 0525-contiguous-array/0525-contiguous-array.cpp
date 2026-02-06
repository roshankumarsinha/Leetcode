class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int maxlen = 0;
        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum = prefixSum + (nums[i] == 0 ? -1 : 1);
            if (mp.count(prefixSum) > 0) {
                maxlen = max(maxlen, i - mp[prefixSum]);
            }
            if (mp.count(prefixSum) == 0) {
                mp[prefixSum] = i;
            }
        }
        return maxlen;
    }
};