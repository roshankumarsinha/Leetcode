class Solution {
public:
    double myPow(double x, int n) {
        long binaryForm = n;
        double result = 1;

        if (binaryForm < 0) {
            binaryForm = -binaryForm; // If n is negative, we will calculate 1/x^n
            x = 1 / x;       // x = 1/x, because x^(-n) = 1/x^n
        }

        while (binaryForm > 0) { // O(logn): We are calculating the power in binary form.
            if (binaryForm % 2 == 1) {
                result = result * x;
            }
            x = x * x; // x^2, x^4, x^8, x^16, x^32, x^64, x^128, x^256, x^512, x^1024
            binaryForm = binaryForm / 2;
        }

        return result;
    }
};