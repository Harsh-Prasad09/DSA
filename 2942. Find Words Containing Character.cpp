class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int n = words.size();

        for (int i = 0; i<n; i++) {
            string word = words[i];

            if (word.contains(x)) ans.push_back(i); 
        }

        return ans;
    }
};
