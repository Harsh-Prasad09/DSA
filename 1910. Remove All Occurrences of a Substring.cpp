class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length() >= part.size() && s.find(part) < s.length()){
            s.erase(s.find(part), part.length());
        }

        return s;
    }
};
