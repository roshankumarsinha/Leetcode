class Solution {
public:
    void combine(int i, vector<int>& candidates, int target, vector<int>& ds,
                 vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        for (int ind = i; ind < candidates.size(); ind++) {
            if (ind > i && candidates[ind] == candidates[ind - 1])
                continue;
            if (candidates[ind] <= target) {
                ds.push_back(candidates[ind]);
                combine(ind + 1, candidates, target - candidates[ind], ds, ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        combine(0, candidates, target, ds, ans);
        return ans;
    }
};