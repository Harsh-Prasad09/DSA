class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = n*(n+1)/2;
        int k = n/m;
        int msum = k*(k+1)*m/2;

        return sum - (2*msum);
    }
};
