// https://leetcode.com/problems/robot-return-to-origin

class Solution {
    public boolean judgeCircle(String moves) {
        int r = 0;
        int c = 0;
        for (int i = 0; i < moves.length(); i++) {
            char ch = moves.charAt(i);
            if (ch == 'U') r++;
            else if (ch == 'D') r--;
            else if (ch == 'R') c++;
            else if (ch == 'L') c--;
        }
        return r == 0 && c == 0;
    }
}