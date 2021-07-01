// https://leetcode.com/problems/graph-connectivity-with-threshold

class Solution {
    public List<Boolean> areConnected(int n, int threshold, int[][] queries) {
        UnionFind union = new UnionFind(n);
        for (int i = threshold + 1; i < n + 1; i++) {
            int num = i;
            for (int j = num + num; j < n + 1; j += num)
                union.unify(num - 1, j - 1);
        }


        List<Boolean> ans = new ArrayList<>();
        for (int[] q: queries){
            if (union.connected(q[0] - 1, q[1] - 1))
                ans.add(true);
            else
                ans.add(false);
        }
        return ans;
    }
    
        class UnionFind {

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
            // zero indexed
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
    private static long gcd(long m, long n) {
        if(n == 0) return m;
        return gcd(n, m % n);
    }
}