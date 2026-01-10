class Solution {
public:
    void reverse(int i, vector<char>& s, int n) {
        if (i >= n / 2) {
            return;
        }
        swap(s[i], s[n - i - 1]);
        reverse(i + 1, s, n);
    }
    void reverseString(vector<char>& s) {
        int n = s.size();
        reverse(0, s, n);
    }
};