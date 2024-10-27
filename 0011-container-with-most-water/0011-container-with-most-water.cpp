class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int lp = 0;                 // Left pointer is at start of array
        int rp = height.size() - 1; // Right Pointer is at end of array
        while (lp < rp) { // Run the loop until unless both become equal or cross-each other
            int width = rp - lp; // Calculate width
            int heightLen = min(height[lp], height[rp]); // Calculate height as minimum value of height[lp] or height[rp]
            int waterStored = width * heightLen; // Calculate height waterStored in that rectangle
            maxWater = max(maxWater, waterStored); // maxWater is previously stored max-water or newly calculated stored-water
            if (height[lp] < height[rp]) { // Decide the height. Whoever is smaller move pointer for that scenario
                lp++;
            } else { // This will handle == condition as well
                rp--;
            }
        }
        return maxWater;
    }
};