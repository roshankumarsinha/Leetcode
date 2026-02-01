/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function (nums, k) {
    let prefixSum = {};
    prefixSum[0] = 1;
    let count = 0;
    let prefixSumVar = 0;
    for (const num of nums) {
        prefixSumVar += num;
        let need = prefixSumVar - k;
        if (prefixSum[need]) {
            count += prefixSum[need];
        }
        if (prefixSum[prefixSumVar]) {
            prefixSum[prefixSumVar]++;
        } else {
            prefixSum[prefixSumVar] = 1;
        }
    }
    return count;
};