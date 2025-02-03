class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxIncreasing = 1, maxDecreasing = 1;
        int inc = 1, dec = 1;
        int n = nums.size();

        for (int i = 1; i<n; i++) {
            if (nums[i] > nums[i-1]) {
                inc++;
                dec = 1;
                maxIncreasing = max(maxIncreasing, inc);
            }
            else if (nums[i] < nums[i-1]){
                dec++;
                inc = 1;
                maxDecreasing = max(maxDecreasing, dec);
            }
            else {
                inc = 1;
                dec = 1;
            }
        }

        return max(maxIncreasing, maxDecreasing);
    }
};
