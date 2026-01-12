class Solution {
public:
    typedef pair<int, pair<int, int>> Node;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Calculate the number of arrays
        int k = nums.size(); // k is the number of arrays
        priority_queue<Node, vector<Node>, greater<Node>>
            minHeap;              // Min-heap to store the elements
        int currentMax = INT_MIN; // Initialize current maximum

        // Insert the first element of each array into the min-heap
        for (int i = 0; i < k; ++i) {
            minHeap.push(
                {nums[i][0],
                 {i,
                  0}}); // Push the first element along with its array and index
            currentMax = max(currentMax, nums[i][0]); // Update current maximum
        }

        int rangeStart = 0, rangeEnd = INT_MAX; // Initialize range

        // While the min-heap is not empty
        while (!minHeap.empty()) {
            Node currentNode = minHeap.top(); // Get the smallest element
            minHeap.pop();                    // Remove it from the heap

            int currentMin =
                currentNode.first; // The minimum value in the current range

            // Update the result range if better
            if (currentMax - currentMin < rangeEnd - rangeStart) {
                rangeStart = currentMin;
                rangeEnd = currentMax;
            }

            // If we can move to the next element in the same array
            if (currentNode.second.second + 1 <
                nums[currentNode.second.first].size()) {
                int nextValue = nums[currentNode.second.first]
                                    [currentNode.second.second + 1];
                minHeap.push({nextValue,
                              {currentNode.second.first,
                               currentNode.second.second +
                                   1}}); // Push the next element into the heap
                currentMax =
                    max(currentMax, nextValue); // Update current maximum
            } else {
                break; // One of the arrays is exhausted, break out of the loop
            }
        }
        vector<int> ans = {rangeStart, rangeEnd};
        return ans; // Return the smallest range
    }
};