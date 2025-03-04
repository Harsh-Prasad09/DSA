class Solution {
public:
    bool checkPowersOfThree(int n) {
        int maxi = 0;
        while (pow(3, maxi) <= n) maxi++;

        for (int i = maxi; i>=0; i--) {
            int num = pow(3, i);
            if (n >= num) n -= num;
        }

        return (n == 0);
    }
};
