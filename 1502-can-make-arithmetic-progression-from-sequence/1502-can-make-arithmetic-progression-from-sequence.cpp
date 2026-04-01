class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();

        // Step 1: find min and max
        int minVal = *min_element(arr.begin(), arr.end());
        int maxVal = *max_element(arr.begin(), arr.end());

        // Step 2: check if valid diff exists
        if ((maxVal - minVal) % (n - 1) != 0)
            return false;

        int d = (maxVal - minVal) / (n - 1);

        // Step 3: handle special case (all elements same)
        if (d == 0)
            return true;

        // Step 4: insert into set
        unordered_set<int> s(arr.begin(), arr.end());

        // Step 5: check all expected values
        for (int i = 0; i < n; i++) {
            int expected = minVal + i * d;
            if (s.find(expected) == s.end())
                return false;
        }

        return true;
    }
};