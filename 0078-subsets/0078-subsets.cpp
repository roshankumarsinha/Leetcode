class Solution {
public:
    void printSubsets(int i, vector<vector<int>>& res, vector<int>& nums,
                      vector<int>& num) {
        if (i == nums.size()) {
            res.push_back(num);
            return;
        }
        num.push_back(nums[i]);
        printSubsets(i + 1, res, nums, num);
        num.pop_back();
        printSubsets(i + 1, res, nums, num);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> num;
        printSubsets(0, res, nums, num);
        return res;
    }
};