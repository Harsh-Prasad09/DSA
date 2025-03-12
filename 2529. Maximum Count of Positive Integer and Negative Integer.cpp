class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int negCnt = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int negPlusZeroCnt = upper_bound(nums.begin(),  nums.end(), 0) - nums.begin();

        return max(negCnt, n - negPlusZeroCnt);
    }
};
