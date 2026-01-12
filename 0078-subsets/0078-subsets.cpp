class Solution {
public:
    void printSubsets(int i, vector<vector<int>>& res, vector<int>& nums,
                      vector<int>& num) {
        res.push_back(num);
        for (int ind = i; ind < nums.size(); ind++) {
            num.push_back(nums[ind]);
            printSubsets(ind + 1, res, nums, num);
            num.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> num;
        printSubsets(0, res, nums, num);
        return res;
    }
};