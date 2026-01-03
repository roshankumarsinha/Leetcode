class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charIndex(256, -1); // Hash map to store the last index of each character
    int left = 0; // Left pointer of the sliding window
    int maxLength = 0; // Maximum length of substring found

    // Expand the window with the right pointer
    for (int right = 0; right < s.length(); right++) {
        char currentChar = s[right];

        // If the character has been seen and is within the current window
        if (charIndex[currentChar] >= left) {
            left = charIndex[currentChar] + 1; // Move left pointer to the right of the last occurrence
        }

        charIndex[currentChar] = right; // Update the last index of the current character
        maxLength = max(maxLength, right - left + 1); // Update maxLength if needed
    }

    return maxLength;
    }
};