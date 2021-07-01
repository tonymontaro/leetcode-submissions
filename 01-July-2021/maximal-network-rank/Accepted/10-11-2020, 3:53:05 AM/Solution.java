// https://leetcode.com/problems/maximal-network-rank

class Solution {
    int best;
    HashSet<Integer>[] aj;
    public int maximalNetworkRank(int n, int[][] roads) {
        best = 0;
        aj = new HashSet[n];
        for (int i = 0; i < n; i++) aj[i] = new HashSet<>();
        for (int[] r : roads) {
            aj[r[0]].add(r[1]);
            aj[r[1]].add(r[0]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sz = aj[i].size() + aj[j].size();
                if (aj[i].contains(j)) sz--;
                best = Math.max(best, sz);
            }
        }
        return best;
    }
}