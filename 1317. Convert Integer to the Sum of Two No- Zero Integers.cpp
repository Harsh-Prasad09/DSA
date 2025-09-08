class Solution {
public:
    bool noZero(int a, int b) {
        while (a > 0) {
            int digit = a % 10;
            a /= 10;

            if (digit == 0) return false;
        }

        while (b > 0) {
            int digit = b % 10;
            b /= 10;

            if (digit == 0) return false;
        }

        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i<n; i++) {
            if (noZero(i, n-i)) return {i, n-i};
        }

        return {};
    }
};
