class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());

        int cnt = 0;
        while (pq.size() > 1) {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();

            if (x >= k) break;

            cnt++;
            pq.push(1ll*2*x + y);
        }

        return cnt;
    }
};
