// https://leetcode.com/problems/rank-transform-of-a-matrix

class Solution {
    HashMap<Integer, TreeSet<Tuple>> rows;
    HashMap<Integer, TreeSet<Tuple>> cols;
    boolean[][] seen;
    public int[][] matrixRankTransform(int[][] matrix) {
//        out.println(matrix);
        int rowlen = matrix.length, colen = matrix[0].length;
        seen = new boolean[rowlen][colen];
        HashMap<Integer, int[]> lastRow = new HashMap<>();
        HashMap<Integer, int[]> lastCol = new HashMap<>();

        rows = new HashMap<>();
        cols = new HashMap<>();

        TreeSet<Tuple> set = new TreeSet<>();
        for (int c = 0; c < colen; c++) cols.put(c, new TreeSet<>());
        for (int r = 0; r < rowlen; r++) {
            rows.put(r, new TreeSet<>());
            for (int c = 0; c < colen; c++) {
                Tuple tuple = new Tuple(matrix[r][c], r, c);
                rows.get(r).add(tuple);
                cols.get(c).add(tuple);
                set.add(tuple);
            }
        }

        while (!set.isEmpty()) {
            Tuple smallest = set.pollFirst();
            int val = smallest.a;
            int r = smallest.b;
            int c = smallest.c;
            if (seen[r][c]) continue;
            List<Tuple> current = new ArrayList<>();
            current.add(smallest);

            add(smallest, smallest.b, current, rows);
            add(smallest, smallest.c, current, cols);
            int rank = -Integer.MAX_VALUE;
            for (Tuple t : current) {
                r = t.b; c = t.c;
                seen[r][c] = true;
                int[] row = !lastRow.containsKey(r) ? new int[]{val, 1} : lastRow.get(r);
                int[] col = !lastCol.containsKey(c) ? new int[]{val, 1} : lastCol.get(c);
                int rowVal = row[0] == val ? row[1] : row[1] + 1;
                int colVal = col[0] == val ? col[1] : col[1] + 1;
                int rank2 = Math.max(rowVal, colVal);
                rank = Math.max(rank, rank2);

            }
            for (Tuple t : current) {
                r = t.b; c = t.c;
                matrix[r][c] = rank;
                lastRow.put(r, new int[]{val, rank});
                lastCol.put(c, new int[]{val, rank});
            }
        }
        return matrix;
    }

    void add(Tuple smallest, int r, List<Tuple> current, HashMap<Integer, TreeSet<Tuple>> rows) {
        while (!rows.get(r).isEmpty() && rows.get(r).first().a <= smallest.a) {
            Tuple item = rows.get(r).pollFirst();
            if (item.a == smallest.a)
                current.add(item);
        }
    }
    
    
    static class Tuple implements Comparable<Tuple> {
        int a;
        int b;
        int c;
        public Tuple(int a, int b) {
            this.a = a;
            this.b = b;
            this.c = 0;
        }
        public Tuple(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
        public int getA() { return a; }
        public int getB() { return b; }
        public int getC() { return c; }
        public int compareTo(Tuple other) {
            if (this.a == other.a) {
                if (this.b == other.b) return Long.compare(this.c, other.c);
                return Long.compare(this.b, other.b);
            }
            return Long.compare(this.a, other.a);
        }
        @Override
        public int hashCode() { return Arrays.deepHashCode(new Integer[]{a, b, c}); }
        @Override
        public boolean equals(Object o) {
            if (!(o instanceof Tuple)) return false;
            Tuple pairo = (Tuple) o;
            return (this.a == pairo.a && this.b == pairo.b && this.c == pairo.c);
        }
        @Override
        public String toString() { return String.format("(%d %d %d)  ", this.a, this.b, this.c); }
    }
}