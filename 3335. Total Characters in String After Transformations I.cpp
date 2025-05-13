class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int mod = 1e9+7;
        vector<int> freq(26, 0);
        for (char ch: s) {
            freq[ch-'a']++;
        }

        while (t--) {
            vector<int> temp(26, 0);
            for (int i = 0; i<26; i++) {
                int num = freq[i];

                if (i != 25) {
                    temp[i+1] = (freq[i])%mod;
                }
                else {
                    temp[0] = (temp[0] + freq[i])%mod;
                    temp[1] = (temp[1] + freq[i])%mod;
                }
            }

            freq = move(temp);
        }

        int length = 0;
        for (int i = 0; i<26; i++) {
            length = (length + freq[i])%mod;
        }
        
        return length;
    }
};
