class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0)
            return 0;

        unordered_map<int, int> freq;

        // Count frequency
        for (int num : nums) {
            freq[num]++;
        }

        int count = 0;

        for (auto& p : freq) {
            int x = p.first;

            if (k > 0) {
                if (freq.count(x + k)) {
                    count++;
                }
            } else { // k == 0
                if (p.second > 1) {
                    count++;
                }
            }
        }

        return count;
    }
};