class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        long long maxDiagonal = 0;

        for (vector<int> dim: dimensions) {
            int l = dim[0];
            int b = dim[1];

            long long diagonal = l*l + b*b;
            if (diagonal > maxDiagonal) {
                maxDiagonal = diagonal;
                maxArea = l * b;
            }
            else if (diagonal == maxDiagonal) maxArea = max(maxArea, l*b);
        }

        return maxArea;
    }
};
