// https://leetcode.com/problems/largest-time-for-given-digits

class Solution {
    public String largestTimeFromDigits(int[] arr) {
        Integer best = null;
        Integer A = null;
        Integer B = null;
        int last = 23 * 60 + 59;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (j == i) continue;
                for (int k = 0; k < 4; k++) {
                    if (k == i || k == j) continue;
                    for (int l = 0; l < 4; l++) {
                        if (l == i || l == j || l == k) continue;
                        int a = arr[i] * 10 + arr[j];
                        int b = arr[k] * 10 + arr[l];
                        if (a >= 24 || b >= 60) continue;
                        int time = 60 * (a) + (b);
                        if (time <= last && (best == null || time > best)) {
                            best = time;
                            A = a;
                            B = b;
                        }
                    }
                }
            }
        }
        if (best == null) return "";

        return String.format("%02d:%02d", A, B);
    }
}