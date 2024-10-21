class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int first = 1, second = 1, maxSum = 1, maxSum2 = 1;
        // Calculate Kadane for both condition

        // 1st Condition bada,chota,bada,chota,....
        for (int i = 1; i < arr.size(); i++) {
            if (i & 1) {
                if (arr[i - 1] > arr[i]) {
                    first = first + 1;
                    maxSum = max(maxSum, first);
                } else {
                    first = 1;
                }
            } else {
                if (arr[i - 1] < arr[i]) {
                    first = first + 1;
                    maxSum = max(maxSum, first);
                } else {
                    first = 1;
                }
            }
        }

        // 2nd condition chota,bada,chota,bada,....
        for (int i = 1; i < arr.size(); i++) {
            if (i & 1) {
                if (arr[i - 1] < arr[i]) {
                    second = second + 1;
                    maxSum2 = max(maxSum2, second);
                } else {
                    second = 1;
                }
            } else {
                if (arr[i - 1] > arr[i]) {
                    second = second + 1;
                    maxSum2 = max(maxSum2, second);
                } else {
                    second = 1;
                }
            }
        }
        cout << "maxSum = " << maxSum;
        return max(maxSum, maxSum2);
    }
};