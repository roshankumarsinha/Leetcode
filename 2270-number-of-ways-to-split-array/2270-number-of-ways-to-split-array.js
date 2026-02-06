/**
 * @param {number[]} nums
 * @return {number}
 */
var waysToSplitArray = function (nums) {
    let sum = 0;
    for (const num of nums) {
        sum += num;
    }

    let prefixSum = 0;
    let count = 0;
    for (let i = 0; i < nums.length - 1; i++) {
        prefixSum += nums[i];
        if (prefixSum >= sum - prefixSum) {
            count++;
        }
    }
    return count;
};