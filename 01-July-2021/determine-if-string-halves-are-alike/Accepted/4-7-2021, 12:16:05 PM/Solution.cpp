// https://leetcode.com/problems/determine-if-string-halves-are-alike

class Solution {
public:
    bool halvesAreAlike(string s) {
        set<char> st = {'a', 'e', 'i', 'o', 'u'};
        int half = s.size() / 2;
        int cnt = 0;
        for (int i = 0; i < half; i++)
            if (st.find(tolower(s[i])) != st.end()) cnt++;
        for (int i = half; i < s.size(); i++)
            if (st.find(tolower(s[i])) != st.end()) cnt--;
        return cnt == 0;
    }
};