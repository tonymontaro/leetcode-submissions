// https://leetcode.com/problems/rank-transform-of-a-matrix

class Solution {
    public int[][] matrixRankTransform(int[][] matrix) {
        int rowlen = matrix.length, colen = matrix[0].length;
//        int[][] ans = new int[rowlen][colen];
        HashMap<Integer, int[]> lastRow = new HashMap<>();
        HashMap<Integer, int[]> lastCol = new HashMap<>();

        HashMap<Integer, HashMap<Integer, Integer>> ansRow = new HashMap<>();
        HashMap<Integer, HashMap<Integer, Integer>> ansCol = new HashMap<>();

        TreeSet<Tuple> cells = new TreeSet<>();
        for (int r = 0; r < rowlen; r++) {
            ansRow.put(r, new HashMap<>());
            for (int c = 0; c < colen; c++) {
                cells.add(new Tuple(matrix[r][c], r, c));
            }
        }
        for (int c = 0; c < colen; c++) ansCol.put(c, new HashMap<>());
        while (!cells.isEmpty()) {
            Tuple smallest = cells.pollFirst();
            int val = smallest.a;
            int r = smallest.b;
            int c = smallest.c;
            int[] row = !lastRow.containsKey(r) ? new int[]{val, 1} : lastRow.get(r);
            int[] col = !lastCol.containsKey(c) ? new int[]{val, 1} : lastCol.get(c);
            int rowVal = row[0] == val ? row[1] : row[1] + 1;
            int colVal = col[0] == val ? col[1] : col[1] + 1;
//            out.pp(val, r, c, Arrays.toString(row), Arrays.toString(col));
            int rank = Math.max(rowVal, colVal);
            ansRow.get(r).put(val, rank);
            ansCol.get(c).put(val, rank);
            lastRow.put(r, new int[]{val, rank});
            lastCol.put(c, new int[]{val, rank});
        }
        for (int r = 0; r < rowlen; r++) {
            for (int c = 0; c < colen; c++) {
                int val = matrix[r][c];
                int rank = Math.max(ansCol.get(c).get(val), ansRow.get(r).get(val));
                matrix[r][c] = rank;
            }
        }

        return matrix;
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