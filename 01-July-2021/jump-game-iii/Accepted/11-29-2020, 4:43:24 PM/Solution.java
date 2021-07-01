// https://leetcode.com/problems/jump-game-iii

class Solution {
    public boolean canReach(int[] arr, int start) {
        int n = arr.length;
        HashSet<Integer> seen = new HashSet<>();
        Deque<Integer> deque = new ArrayDeque<>();
        deque.addLast(start);
        seen.add(start);
        while (!deque.isEmpty()) {
            int idx = deque.pollFirst();
            int num = arr[idx];
            if (num == 0)
                return true;
            for (int i : new int[]{idx + num, idx - num}) {
                if (i >= 0 && i < n && !seen.contains(i)) {
                    seen.add(i);
                    deque.add(i);
                }
            }
        }
        return false;
    }
}