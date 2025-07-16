class Solution {
public:
    int solve(vector<int> &nums) {
        int cnt = 0;
        int odd = nums[0] % 2 == 1;
        for (int num: nums) {
            if (odd && num % 2 == 1) {
                cnt++;
                odd = !odd;
            }
            else if (!odd && num % 2 == 0) {
                cnt++;
                odd = !odd;
            }
        }

        return cnt;
    }

    int maximumLength(vector<int>& nums) {
        int odd = 0, even = 0;
        for (int num: nums) {
            if (num % 2 == 0) even++;
            else odd++;
        }

        int oddEven = solve(nums);

        return max({even, odd, oddEven});
    }
};
