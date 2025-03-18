class Solution {
public:
    bool isPossible(int num, vector<int> freq) {
        for (int i = 0; i<32; i++) {
            freq[i] += (1 & (num>>i));

            if (freq[i] > 1) return false;
        }

        return true;
    }

    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        vector<int> freq(32, 0);

        int maxi = 0;
        while (j < n) {
            if (isPossible(nums[j], freq)) {
                int num = nums[j];
                j++;
                for (int k = 0; k<32; k++) {
                    freq[k] += (1 & (num>>k));
                }
            }
            else {
                int num = nums[i];
                i++;
                for (int k = 0; k<32; k++) {
                    freq[k] -= (1 & (num>>k));
                }
            }

            maxi = max(maxi, j - i);
        }

        return maxi;
    }
};
