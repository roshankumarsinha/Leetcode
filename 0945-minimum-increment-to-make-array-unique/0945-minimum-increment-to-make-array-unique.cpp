class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        int maxVal = 0; // To track maximum value in arr

        for (int num : nums) {
            freqMap[num]++;
            maxVal = max(maxVal, num);
        }

        int operations = 0;
        // Fixed upper bound: maxVal + n covers worst case (all elements same
        // value)
        for (int i = 0; i < maxVal + (int)nums.size(); i++) {
            if (freqMap.count(i) && freqMap[i] > 1) {
                int duplicates =
                    freqMap[i] - 1;       // Number of duplicates at value i
                operations += duplicates; // Each duplicate needs 1 operation to
                                          // move to next value
                freqMap[i + 1] += duplicates; // Push duplicates to next value
            }
        }
        return operations;
    }
};