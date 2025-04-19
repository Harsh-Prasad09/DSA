class Solution {
private:
    long long lower_bound(vector<int> &nums, int low, int high, int num){
        while(low <= high){
            int mid = low + (high - low)/2;
            if (nums[mid] >= num) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0ll;
        int n = nums.size();
        
        for (int i = 0; i<n; i++){
            int low = lower_bound(nums, i+1, n-1, lower-nums[i]);
            int high = lower_bound(nums, i+1, n-1, upper-nums[i]+1);
            ans += 1ll*(high - low);
        }
        
        return ans;
    }
};
