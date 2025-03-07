class Solution {
public:
    vector<int> sieve(int n) {
        vector<int> primes(n+1, 1);
        primes[1] = 0;
        for (int p = 2; p*p <= n; p++) {
            if (primes[p] == true) {
                for (int i = p*p; i <= n; i += p) {
                    primes[i] = 0;
                }
            }
        }

        return primes;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primes = sieve(right+1);
        vector<int> nums;
        for (int i = left; i<= right; i++) {
            if (primes[i]) nums.push_back(i);
        }

        if (nums.size() < 2) return {-1, -1};
        int mini = 1e9;
        vector<int> ans;
        for (int i = 1; i<nums.size(); i++) {
            int diff = nums[i] - nums[i-1];
            if (mini > diff) {
                mini = diff;
                ans = {nums[i-1], nums[i]};
            }
        }

        return ans;
    }
};
