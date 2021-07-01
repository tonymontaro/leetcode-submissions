// https://leetcode.com/problems/k-empty-slots

class Solution {
    public int kEmptySlots(int[] bulbs, int k) {
        TreeSet<Integer> set = new TreeSet<>();
        int day = 0;
        for (int b : bulbs) {
            day += 1;
            Integer lower = set.lower(b);
            if (lower != null && b - lower - 1 == k)
                return day;
            Integer higher = set.higher(b);
            if (higher != null && higher - b - 1 == k)
                return day;
            set.add(b);
        }
        return -1;
    }
}