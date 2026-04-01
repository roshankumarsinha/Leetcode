class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // pointer for s

        for (int j = 0; j < t.size(); j++) {
            if (i < s.size() && s[i] == t[j]) {
                i++;
            }
        }

        return i == s.size();
    }
};