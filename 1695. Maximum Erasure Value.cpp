class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxSum = 0;
        int i = 0, j = 0;

        vector<int> freq(10001, 0);
        while (j < n) {
            while (j < n && freq[nums[j]] == 0) {
                freq[nums[j]]++;
                sum += nums[j];
                j++;
            }

            maxSum = max(maxSum, sum);

            freq[nums[i]]--;
            sum -= nums[i];
            i++;
        }

        return maxSum;
    }
};
