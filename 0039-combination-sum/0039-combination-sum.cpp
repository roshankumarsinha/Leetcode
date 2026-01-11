class Solution {
public:
    void solve(vector<int>& candidates, int target, int index,
               vector<int>& current, vector<vector<int>>& result, int sum) {
        if (target == sum) {
            result.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (sum + candidates[i] <= target) {
                current.push_back(candidates[i]);
                solve(candidates, target, i, current, result,
                      sum + candidates[i]);
                current.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        int sum = 0;
        solve(candidates, target, 0, current, result, 0);
        return result;
    }
};