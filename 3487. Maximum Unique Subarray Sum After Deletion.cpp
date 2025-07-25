class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        if (maxi < 0) return maxi;

        unordered_set<int> st(nums.begin(), nums.end());
        int sum = 0;
        for (int num: st) {
            if (num > 0) sum += num;
        }

        return sum;
    }
};
