class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for (char &ch: s) {
            char c = tolower(ch);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowels.emplace_back(ch);
        }

        if (!vowels.empty()) sort(vowels.begin(), vowels.end());

        int idx = 0;
        int n = s.length();
        for (int i = 0; i<n; i++) {
            char c = tolower(s[i]);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                s[i] = vowels[idx++];
        }

        return s;
    }
};
