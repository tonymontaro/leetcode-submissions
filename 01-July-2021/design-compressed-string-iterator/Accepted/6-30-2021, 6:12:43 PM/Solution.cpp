// https://leetcode.com/problems/design-compressed-string-iterator

class StringIterator {
public:
    int i = 0, sz = 0;
    char c;
    string s;
    StringIterator(string compressedString) {
        s = compressedString;
    }

    char next() {
        if (sz > 0) {
            sz--; 
            return c;
        }
        if (i >= s.size()) return ' ';
        c = s[i++];
        int num = 0;
        while (i < s.size() && isdigit(s[i])) {
            num = num * 10 + (s[i++] - '0');
        }
        sz = num - 1;
        return c;
    }

    bool hasNext() {
        return i < s.size() || sz > 0;
    }
};