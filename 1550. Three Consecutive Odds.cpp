class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;

        int prod = arr[0] * arr[1] * arr[2];
        for (int i = 3; i<n; i++) {
            if (prod % 2 == 1) return true;

            prod /= arr[i-3];
            prod *= arr[i];
        }

        return (prod % 2 == 1);
    }
};
