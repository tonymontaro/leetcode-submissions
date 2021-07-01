// https://leetcode.com/problems/is-graph-bipartite

class Solution {
    int[][] aj;
    int[] colors;
    boolean valid;
    public boolean isBipartite(int[][] graph) {
        aj = graph;
        int n = graph.length;
        if (n < 1) return true;
        colors = new int[n];
        valid = true;
        for (int i = 0; i < n; i++) if (colors[i] == 0) dfs(i, 0);
        return valid;
    }

    void dfs(int node, int color) {
        if (colors[node] > 0) {
            if (colors[node] != color) valid = false;
            return;
        }
        colors[node] = color;
        int nextColor = color == 1 ? 2 : 1;
        for (int child: aj[node])
            dfs(child, nextColor);
    }

}