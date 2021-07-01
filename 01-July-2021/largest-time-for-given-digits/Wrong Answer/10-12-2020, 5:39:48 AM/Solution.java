// https://leetcode.com/problems/largest-time-for-given-digits

class Solution {
    public String largestTimeFromDigits(int[] arr) {
        Integer best = null;
        int a = 0;
        int b = 0;
        for (int i = 0; i < 4; i++) {
            int h = arr[i] * 10;
            for (int j = 0; j < 4; j++) {
                if (j == i || h + arr[j] >= 24) continue;
                int v = h + arr[j];
                if (best == null || v > best) {
                    best = v;
                    a = i; b = j;
                }
            }
        }
        if (best == null) return "";
        List<Integer> ar = new ArrayList<>();
        for (int i = 0; i < 4; i++) if (i != a && i != b) ar.add(arr[i]);
        Integer other = null;
        a = ar.get(0);
        b = ar.get(1);
        int v1 = a*10 + b;
        if (v1 < 60) other = v1;
        int v2 = b*10 + a;
        if (v2 < 60 && (other == null || v2 > v1)) other = v2;
        if (other == null) return "";
        return String.format("%02d:%02d", best, other);
    }

}