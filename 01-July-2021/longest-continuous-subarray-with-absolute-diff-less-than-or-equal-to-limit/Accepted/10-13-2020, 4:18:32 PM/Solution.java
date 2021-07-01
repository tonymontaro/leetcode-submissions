// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit

class Solution {
    public int longestSubarray(int[] nums, int limit) {
        // O(nlogn) time | o(n) space
        HashMap<Integer, Integer> count = new HashMap<>();
        TreeSet<Integer> set = new TreeSet<>();
        Deque<Integer> deque = new ArrayDeque<>();
        int best = 0;
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            count.merge(num, 1, Integer::sum);
            set.add(num);
            deque.addLast(num);
            while (set.last() - set.first() > limit) {
                int last = deque.pollFirst();
                count.merge(last, -1, Integer::sum);
                if (count.get(last) <= 0)
                    set.remove(last);
            }
            best = Math.max(best, deque.size());
        }
        return best;
    }
}