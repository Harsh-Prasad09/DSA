class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int cnt = 0;
        unordered_set<char> st(brokenLetters.begin(), brokenLetters.end());

        stringstream ss(text);
        string word;

        while (ss >> word) {
            bool flag = true;
            for (char ch: word) {
                if (st.count(ch) != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) cnt++;
        }

        return cnt;
    }
};
