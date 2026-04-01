class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // Step 1: sort
        sort(arr.begin(), arr.end());

        // Step 2: find common difference
        int diff = arr[1] - arr[0];

        // Step 3: check all consecutive differences
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != diff) {
                return false;
            }
        }

        return true;
    }
};