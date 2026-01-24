class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;

        // Step 1: Insert all elements into HashMap (value can be used to mark
        // visited)
        unordered_set<int> numMap(nums.begin(), nums.end());
        // unordered_map<int, bool> numMap;
        // for (int num : nums) {
        //     numMap[num] = true;
        // }

        int maxLen = 0;

        // Step 2: Find sequence starters and count
        for (int num : numMap) {
            // Check if this is the start of a sequence
            if (numMap.find(num - 1) == numMap.end()) {
                // num - 1 doesn't exist, so num is a sequence start
                int currentNum = num;
                int currentLen = 1;

                // Count consecutive elements
                while (numMap.find(currentNum + 1) != numMap.end()) {
                    currentNum++;
                    currentLen++;
                }

                maxLen = max(maxLen, currentLen);
            }
        }

        return maxLen;
    }
};