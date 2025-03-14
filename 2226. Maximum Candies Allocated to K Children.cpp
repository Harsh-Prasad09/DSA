class Solution {
public:
    bool f(long long mid, vector<int> &candies, long long k) {
        long long cnt = 0;
        for (int num: candies) {
            cnt += (num / mid);
        }

        return (cnt >= k);
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int mini = 1, maxi = *max_element(candies.begin(), candies.end());
        
        int ans = 0;
        while(mini <= maxi) {
            long long mid = mini + (maxi - mini)/2;
            if (f(mid, candies, k)) ans = mid, mini = mid + 1;
            else maxi = mid - 1;
        }

        return ans;
    }
};
