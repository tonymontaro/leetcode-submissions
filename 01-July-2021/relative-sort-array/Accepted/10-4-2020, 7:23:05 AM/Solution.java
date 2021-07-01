// https://leetcode.com/problems/relative-sort-array

class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        HashSet<Integer> set = new HashSet<>();
        for (int num: arr2) set.add(num);
        List<Integer> other = new ArrayList<>();
        HashMap<Integer, Integer> count = new HashMap<>();
        for (int num : arr1) {
            if (set.contains(num)) count.merge(num, 1, Integer::sum);
            else other.add(num);
        }
        Collections.sort(other);
        int[] res = new int[arr1.length];
        int idx = 0;
        for (int num : arr2) {
            for (int i = 0; i < count.get(num); i++) res[idx++] = num;
        }
        for (int num: other) res[idx++] = num;
        return res;
    }
}