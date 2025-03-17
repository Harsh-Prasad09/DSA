class Solution {
public:
    bool isPossible(long long mid, vector<int> &ranks, int cars) {
        long long cnt = 0ll;
        for (int rank: ranks) {
            cnt += 1ll*sqrt(mid/rank);
        }

        return cnt>=cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long mini = 1ll;
        long long maxi = *max_element(ranks.begin(), ranks.end())*1ll*cars*cars;

        long long ans = 0ll;
        while(mini <= maxi) {
            long long mid = mini + (maxi - mini)/2;

            if (isPossible(mid, ranks, cars)) {
                ans = mid;
                maxi = mid - 1;
            }
            else mini = mid + 1;
        }

        return ans;
    }
};
