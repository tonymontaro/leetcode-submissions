// https://leetcode.com/problems/student-attendance-record-i

class Solution {
    public boolean checkRecord(String seq) {
        int n = seq.length();
        int consec = 0;
        int aCount = 0;
        int idx = 0;
        while (idx < n) {
            char ch = seq.charAt(idx++);
            if (ch == 'L') {
                int i = idx - 1;
                while (idx < n && seq.charAt(idx) == 'L') idx++;
                consec = Math.max(consec, idx - i);
            } else if (ch == 'A') aCount++;
        }
        return (consec <= 2 && aCount <= 1); 
    }
}