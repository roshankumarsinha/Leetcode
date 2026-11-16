function majorityElement(nums: number[]): number {
    let can = 0;
    let ct = 0;
    for (const val of nums) {
        if (ct == 0) {
            can = val;
            ct = 1;
        } else if (val == can) {
            ct++;
        } else {
            ct--;
        }
    }
    return can;
};