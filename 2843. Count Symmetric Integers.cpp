class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (int num = low; num <= high; num++){
            if (num < 100 && num % 11 == 0) cnt++;
            else if (num > 1000 && num <= 9999) {
                int leftSum = (num/1000) + (num%1000)/100;
                int rightSum = (num%100)/10 + (num%10);

                if (leftSum == rightSum) cnt++;
            }
        }

        return cnt;
    }
};
