class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> charCount(
            26, 0); // Frequency map for characters A-Z, index 0 for 'A', 1 for
                    // 'B', ..., 25 for 'Z', initialized to 0
        int left = 0;         // Left pointer of the sliding window
        int maxFreqCount = 0; // Count of the most frequent character in the
                              // current window, initialized to 0
        int maxLength =
            0; // Maximum length of the window found, initialized to 0

        // Expand the window with the right pointer
        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];
            charCount[currentChar -
                      'A']++; // Update frequency of the current character

            // Update maxFreqCount if needed
            maxFreqCount = max(maxFreqCount, charCount[currentChar - 'A']);

            // If the number of characters to replace exceeds k, shrink the
            // window from the left We need to check condition: (window size -
            // maxFreqCount) > k, right - left + 1 is window size
            while ((right - left + 1) - maxFreqCount > k) {
                char leftChar = s[left];
                charCount[leftChar -
                          'A']--; // Decrease frequency of the left character
                left++;           // Move left pointer to the right

                // Recalculate maxFreqCount for the current window
                // If we want to improve time complexity, from O(N*26) to O(N),
                // we can avoid recalculating maxFreqCount every time. Why we
                // can skip recalculating maxFreqCount every time? Since we are
                // only reducing the count of one character (the leftmost
                // character) when we shrink the window, the maxFreqCount can
                // only decrease if the character we are removing was the one
                // contributing to maxFreqCount. However, if we keep track of
                // the maximum frequency character while expanding the window,
                // we can avoid recalculating it every time we shrink the
                // window. window size - maxFreqCount > k means we have more
                // than k characters to replace, and we are removing one
                // character from the left, means we are reducing window size,
                // so decreasing maxFreqCount will only make the condition more
                // likely to be satisfied. Hence, we can afford to recalculate
                // maxFreqCount only when necessary.
                maxFreqCount = 0;
                for (int count : charCount) {
                    maxFreqCount = max(maxFreqCount, count);
                }
            }

            // Update maxLength
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};