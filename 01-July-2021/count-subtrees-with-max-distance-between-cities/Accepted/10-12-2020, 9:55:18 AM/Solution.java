// https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities

class Solution {
    public int[] countSubgraphsForEachDiameter(int n, int[][] edges) {
        int[][] distances = new int[n][n];
        fill(distances, 1000);
        for (int[] edge : edges) {
            int a = edge[0] - 1, b = edge[1] - 1;
            distances[a][b] = 1;
            distances[b][a] = 1;
        }
        // Floyd-Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    distances[i][j] = Math.min(distances[i][j], distances[i][k] + distances[k][j]);
                }
            }
        }

        int[] res = new int[n - 1];
        int maxBitMask = 1 << n;
        for (int mask = 2; mask < maxBitMask; mask++) {
            int numNodes = Integer.bitCount(mask);
            if (numNodes <= 1) continue;
            // Sub-Tree
            int maxDistance = 0;
            int numEdges = 0;
            for (int i = 0; i < n; i++) {
                if (((1 << i) & mask) != 0) {
                    for (int j = i + 1; j < n; j++) {
                        if (((1 << j) & mask) != 0) {
                            int dist = distances[i][j];
                            if (dist == 1) numEdges++;
                            maxDistance = Math.max(maxDistance, dist);
                        }
                    }
                }
            }
            boolean isValidSubTree = numEdges == (numNodes - 1);
            if (isValidSubTree) res[maxDistance - 1]++;
        } 

        return res;
    }
    private static void fill(int[][] ob, int res){      for(int i=0; i<ob.length; i++){ for(int j=0; j<ob[0].length; j++){  ob[i][j] = res; }}}

}