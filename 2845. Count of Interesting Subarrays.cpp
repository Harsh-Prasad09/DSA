class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        long long ans = 0;
        int prefix = 0;
        for(int i = 0; i<n; i++){
            prefix += ((nums[i] % modulo) == k);
            ans += mpp[(prefix + modulo - k) % modulo];
            mpp[prefix % modulo]++;
        }
        return ans;
    }
};
