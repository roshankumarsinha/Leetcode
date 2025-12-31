class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> charCount(
            3, 0);    // Frequency map for characters 'a', 'b', 'c', index 0 for
                      // 'a', 1 for 'b', 2 for 'c', initialized to 0
        int left = 0; // Left pointer of the sliding window
        int count = 0; // Count of substrings containing all three characters

        // Expand the window with the right pointer
        for (int right = 0; right < s.length(); right++) {
            charCount[s[right] -
                      'a']++; // Update frequency of the current character

            // While the current window contains at least one occurrence of all
            // three characters charCount[0] represents count of 'a'
            // charCount[1] represents count of 'b'
            // charCount[2] represents count of 'c'
            // so, if all three counts are greater than 0, we have at least one
            // occurrence of each character in the current window.
            while (charCount[0] > 0 && charCount[1] > 0 && charCount[2] > 0) {
                // Calculate the number of substrings that can be formed with
                // the current window
                count =
                    count + (s.length() -
                             right); // All substrings starting from left to end
                                     // of string with current right pointer

                // Shrink the window from the left
                charCount[s[left] - 'a']--; // Update frequency of the character
                                            // at the left pointer
                left++; // Move the left pointer to the right
            }
        }

        return count; // Return the total count of substrings
    }
};