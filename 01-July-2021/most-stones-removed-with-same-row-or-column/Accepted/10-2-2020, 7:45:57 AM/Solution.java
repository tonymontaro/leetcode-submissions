// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

class Solution {
    public int removeStones(int[][] stones) {
        int n = stones.length;
        UnionFind disjoint = new UnionFind(n);
        HashMap<Integer, Integer> colGroup = new HashMap<>();
        HashMap<Integer, Integer> rowGroup = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int[] s = stones[i];
            if (colGroup.containsKey(s[0])) disjoint.unify(i, colGroup.get(s[0]));
            else colGroup.put(s[0], i);

            if (rowGroup.containsKey(s[1])) disjoint.unify(i, rowGroup.get(s[1]));
            else rowGroup.put(s[1], i);
        }
        HashSet<Integer> seen = new HashSet<>();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int parent = disjoint.find(i);
            if (seen.contains(parent)) continue;
            ans += disjoint.getSize(parent) - 1;
            seen.add(parent);
        }

        return ans;
    }

    public class UnionFind {

        private final int size;
        private int groups;
        private final int[] sizes;
        private final int[] parents;

        public int getSize() {
            return size;
        }

        public int getGroups() {
            return groups;
        }

        public int getSize(int p) {
            return sizes[find(p)];
        }

        public UnionFind(int n) {
            this.size = this.groups = n;
            sizes = new int[n];
            parents = new int[n];

            for (int i = 0; i < n; i++) {
                parents[i] = i;
                sizes[i] = 1;
            }
        }

        public int find(int p) {
            int root = p;
            while (root != parents[root]) root = parents[root];

            while (p != root) {
                int temp = parents[p];
                parents[p] = root;
                p = temp;
            }
            return root;
        }

        public boolean connected(int p, int q) {
            return find(p) == find(q);
        }

        public void unify(int p, int q) {
            int root1 = find(p);
            int root2 = find(q);
            if (root1 == root2) return;

            if (sizes[root1] < sizes[root2]) {
                parents[root1] = root2;
                sizes[root2] += sizes[root1];
            } else {
                parents[root2] = root1;
                sizes[root1] += sizes[root2];
            }
            groups--;
        }

    }
}