class Solution {

private:
    vector<int> nextSmallerIndex(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            int cur = arr[i];
            while (s.top() != -1 && arr[s.top()] >= cur) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

    vector<int> prevSmallerIndex(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int cur = arr[i];
            while (s.top() != -1 && arr[s.top()] >= cur) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // This stores indexes of next Smaller Element
        vector<int> next(n);
        next = nextSmallerIndex(heights, n);

        // This stores indexes of previous Smaller Element
        vector<int> prev(n);
        prev = prevSmallerIndex(heights, n);

        int maxArea = INT_MIN;

        for (int i = 0; i < n; i++) {
            int length = heights[i];

            // If next[i] == -1, that means we have travelled till last index so
            // to avoid -ve area we have to set till length of array
            if (next[i] == -1) {
                next[i] = n;
            }

            int breadth = next[i] - prev[i] - 1;
            int newArea = length * breadth;
            maxArea = max(maxArea, newArea);
        }

        return maxArea;
    }
};