class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, pair<int, int>> fm;
        int left = 0;
        int maxi = 0;
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            if (fm[c].first !=0 && fm[c].second >= left) {
                left = fm[c].second + 1;
            }
            int val = fm[c].first + 1;
            fm[c] = {val, right};
            maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }
};