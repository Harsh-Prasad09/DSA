class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff = 0;
        int n = s1.size();

        if (n != s2.size()) return false;
        unordered_map<char, int> freq1, freq2;

        for (int i = 0; i<n; i++) {
            freq1[s1[i]]++;
            freq2[s2[i]]++;
            if (s1[i] != s2[i]) diff++;
        }

        return (freq1 == freq2) && (diff == 0 || diff == 2);
    }
};
