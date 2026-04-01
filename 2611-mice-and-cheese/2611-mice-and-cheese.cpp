class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        
        vector<int> diff(n);
        int total = 0;
        
        // Step 1: Assume all go to mouse2
        for (int i = 0; i < n; i++) {
            total += reward2[i];
            diff[i] = reward1[i] - reward2[i];
        }
        
        // Step 2: Sort differences descending
        sort(diff.begin(), diff.end(), greater<int>());
        
        // Step 3: Pick top k
        for (int i = 0; i < k; i++) {
            total += diff[i];
        }
        
        return total;
    }
};