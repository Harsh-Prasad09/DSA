class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int mini = n;
        int whiteCnt = 0;
        
        int i;
        for (i = 0; i<k; i++) {
            if (blocks[i] == 'W') whiteCnt++;
        }

        mini = min(mini, whiteCnt);
        for (int j = i; j<n; j++) {
            if (blocks[j] == 'W') whiteCnt++;
            if (blocks[j-k] == 'W') whiteCnt--;
            mini = min(mini, whiteCnt);
        }

        return mini;
    }
};
