/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function (nums, k) {
    let reverse = function (i, j) {
        while (i < j) {
            let temp = nums[i]
            nums[i] = nums[j]
            nums[j] = temp
            i++
            j--
        }
    }
    let size = nums.length;
    k = k % size;
    if (k === 0) return ;
    reverse(0, size - 1);
    reverse(0, k - 1);
    reverse(k, size - 1);

};