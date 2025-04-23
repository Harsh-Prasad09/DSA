class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mpp;
        int maxi = 0;
        for (int i = 1; i<=n; i++) {
            int num = i;
            int sum = 0;
            while (num) {
                sum += (num % 10);
                num /= 10;
            }

            mpp[sum]++;
            maxi = max(maxi, mpp[sum]);
        }

        int cnt = 0;
        for (auto &[key, val] : mpp) {
            if (val == maxi) cnt++;
        }

        return cnt;
    }
};
