class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        int dominant = 0;

        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;

            if (freq[nums[i]] > n/2){
                dominant = nums[i];
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == dominant) {
                cnt++;
                freq[nums[i]]--;
                if((cnt > (i+1)/2) && (freq[nums[i]] > (n-i-1)/2)) {
                    return i;
                }
            }
        }
        
        return -1;
    }
};
