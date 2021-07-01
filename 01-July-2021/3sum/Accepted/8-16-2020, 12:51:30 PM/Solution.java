// https://leetcode.com/problems/3sum

class Solution {
    public static List<List<Integer>> threeSum(int[] arr) {
        int n = arr.length;
        List<List<Integer>> res = new ArrayList<>();
        HashSet<List<Integer>> seenRes = new HashSet<>();
        for (int i = 0; i < n; i++) {
            int target = 0 - arr[i];
            HashSet<Integer> seen = new HashSet<>();
            for (int j = i + 1; j < n; j++) {
                if (seen.contains(target - arr[j])) {
                    List<Integer> rs = new ArrayList<>();
                    rs.add(arr[i]);
                    rs.add(target - arr[j]);
                    rs.add(arr[j]);

                    Collections.sort(rs);
                    if (!seenRes.contains(rs)) {
                        seenRes.add(rs);
                        res.add(rs);
                    }
                }
                seen.add(arr[j]);
            }
        }
        return res;
    }
}