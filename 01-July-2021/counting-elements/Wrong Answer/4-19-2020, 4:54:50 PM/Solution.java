// https://leetcode.com/problems/counting-elements

import java.util.*;

class Solution {
    public int countElements(int[] nums) {
        // O(n) time and space
        HashSet<Integer> seen = new HashSet<>();
        for (int num: nums) seen.add(num);

        int result = 0;
        for (int num: seen) {
            if (seen.contains(num + 1)) result++;
        }
        return result;
    }
}