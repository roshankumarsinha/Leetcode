class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();

        int left = 0;
        int cost = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {
            // add current cost
            cost += abs(s[right] - t[right]);

            // shrink window if cost exceeds
            while (cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                left++;
            }

            // update max length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};