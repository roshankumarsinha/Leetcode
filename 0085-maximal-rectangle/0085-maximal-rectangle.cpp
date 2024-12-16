class Solution {
    vector<int> nextSmallerElement(vector<int> arr, int n) {
        vector<int> result(n);
        stack<int> s;
        s.push(-1);
        for (int i = n - 1; i >= 0; --i) {
            int current = arr[i];
            while (s.top() != -1 && arr[s.top()] >= current) {
                s.pop();
            }
            result[i] = s.top();
            s.push(i);
        }

        return result;
    }

    vector<int> prevSmallerElement(vector<int> arr, int n) {
        vector<int> result(n);
        stack<int> s;
        s.push(-1);
        for (int i = 0; i < n; i++) {
            int current = arr[i];
            while (s.top() != -1 && arr[s.top()] >= current) {
                s.pop();
            }
            result[i] = s.top();
            s.push(i);
        }

        return result;
    }
    int largestRectangleArea(vector<int> heights, int n) {
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        int maxArea = INT_MIN;

        for (int i = 0; i < n; i++) {
            int length = heights[i];
            if (next[i] == -1) {
                next[i] = n;
            }

            int breadth = next[i] - prev[i] - 1;
            int newArea = length * breadth;
            maxArea = max(maxArea, newArea);
        }

        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Converting string matrix to Number matrix, so that mathematic
        // operations become easy
        vector<vector<int>> mt(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mt[i][j] = matrix[i][j] - '0';
            }
        }

        // Calculate LargestAreaInHistogram for 1st row
        int maxArea = largestRectangleArea(mt[0], cols);

        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Add all the previous rows height to current row
                if (mt[i][j] != 0) {
                    mt[i][j] = mt[i][j] + mt[i - 1][j];
                } else { // If current row has value 0 that means that building
                         // can't be possible
                    mt[i][j] = 0;
                }
            }
            // Calculate LargestAreaInHistogram in for all the rows
            maxArea = max(maxArea, largestRectangleArea(mt[i], cols));
        }

        return maxArea;
    }
};