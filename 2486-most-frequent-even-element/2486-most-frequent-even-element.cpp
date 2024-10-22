class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(int value:nums) {
            if (value % 2 == 0) {
                mp[value]++;
            }
        }
        int max = 0;
        int ele = -1;
        for (auto el=mp.begin(); el!=mp.end(); el++) {
            if (el->second > max) {
                max = el->second;
                ele = el->first;
            }
            else if (el->second == max && el->first < ele) {
                ele = el->first;
            }
        }
        return ele;
    }
};