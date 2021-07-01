// https://leetcode.com/problems/combination-sum

class Solution {

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>>[] dp = new ArrayList[target + 1];
        dp[0] = new ArrayList<>();
        dp[0].add(new ArrayList<>());
        sort(candidates);
        for (int k : candidates) {
            for (int i = k; i < target + 1; i++) {
                if (dp[i - k] == null) continue;
                if (dp[i] == null) dp[i] = new ArrayList<>();
                List<List<Integer>> prev = dp[i - k];
                for (List<Integer> pr : prev) {
                    List<Integer> cr = new ArrayList<>(pr);
                    cr.add(k);
                    dp[i].add(cr);
                }
            }
        }

        return dp[target] == null ? new ArrayList<>() : dp[target];
    }
    static final Random random = new Random();
    static void sort(int[] a) {
        int n = a.length;// shuffle, then sort
        for (int i = 0; i < n; i++) {
            int oi = random.nextInt(n), temp = a[oi];
            a[oi] = a[i];
            a[i] = temp;
        }
        Arrays.sort(a);
    }
}