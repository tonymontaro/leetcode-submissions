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
        int other = Math.max(ar.get(0) * 10 + ar.get(1), ar.get(1) * 10 + ar.get(0));
        return String.format("%02d:%02d", best, other);
    }

}