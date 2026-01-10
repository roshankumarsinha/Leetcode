class Solution {
public:
    void printSubsets(int i, vector<vector<int>>& res, vector<int>& nums, int n,
                      vector<int>& num) {
        if (i == n) {
            res.push_back(num);
            return;
        }
        num.push_back(nums[i]);
        printSubsets(i + 1, res, nums, n, num);
        num.pop_back();
        printSubsets(i + 1, res, nums, n, num);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> num;
        int n = nums.size();
        printSubsets(0, res, nums, n, num);
        return res;
    }
};