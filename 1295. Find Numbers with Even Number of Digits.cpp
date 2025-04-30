class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (int num: nums){
            int noOfDigits = 0;
            while(num > 0){
                noOfDigits++;
                num /= 10;
            }
            
            if ((noOfDigits & 1) == 0) cnt++;
        }
        return cnt;
    }
};
