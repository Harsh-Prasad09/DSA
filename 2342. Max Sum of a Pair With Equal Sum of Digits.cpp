class Solution {
public:
    int findSumOfDigits(int num) {
        int sum = 0;
        while(num > 0) {
            sum += num%10;
            num = num/10;
        }

        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>> mpp;
        for (int num: nums) {
            int sum = findSumOfDigits(num);
            mpp[sum].push(num);
        }

        int maxi = -1;
        for (auto it: mpp) {
            priority_queue<int> temp = it.second;
            if (temp.size() > 1) {
                int g1 = temp.top();
                temp.pop();
                int g2 = temp.top();
                maxi = max(maxi, g1+g2);
            }
        }

        return maxi;
    }
};
