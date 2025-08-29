class Solution {
public:
    long long flowerGame(int n, int m) {
        long long oddN = (n+1)/2;
        long long evenN = n - oddN;

        long long oddM = (m+1)/2;
        long long evenM = m - oddM;

        return (oddN*evenM) + (oddM*evenN);
    }
};
