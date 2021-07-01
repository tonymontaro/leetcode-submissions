// https://leetcode.com/problems/remove-covered-intervals

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        // O(nlogn) time | O(n) space
        int n = intervals.length;
        Tuple[] nodes = new Tuple[n];
        for (int i = 0; i < n; i++) {
            int a = intervals[i][0], b = intervals[i][1];
            nodes[i] = new Tuple(a, b);
        }
        Arrays.sort(nodes);
        int count = 0;
        int mxStart = -1;
        int mxEnd = -1;
        for (Tuple node : nodes) {
            if (node.a > mxStart && node.b > mxEnd) count++;
            mxStart = Math.max(mxStart, node.a);
            mxEnd = Math.max(mxEnd, node.b);
        }
        return count;
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
                return Long.compare(other.b, this.b);
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