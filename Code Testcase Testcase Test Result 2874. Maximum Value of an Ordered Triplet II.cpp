class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxVal = 0ll, maxDiff = 0ll, maxNum = 0ll;

        for (int i = 0; i<nums.size(); i++) {
            long long num = 1ll*nums[i];

            maxVal = max(maxVal, maxDiff * num);
            maxDiff = max(maxDiff, maxNum - num);
            maxNum = max(maxNum, num);
        }

        return maxVal;
    }
};
