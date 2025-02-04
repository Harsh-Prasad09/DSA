class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int sum = 0;

        for (int i = 0; i<n; i++) {
            if (i != 0 && nums[i] > nums[i-1]) {
                sum += nums[i];
            }
            else {
                maxi = max(maxi, sum);
                sum = nums[i];
            }
        }
        return max(sum, maxi);
    }
};
