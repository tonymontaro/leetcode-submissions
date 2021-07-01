// https://leetcode.com/problems/remove-covered-intervals

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        // O(nlogn) time | O(n) space
        TreeSet<Tuple> starts = new TreeSet<>();
        TreeSet<Tuple> ends = new TreeSet<>();
        for (int[] interval : intervals) {
            int a = interval[0], b = interval[1];
            starts.add(new Tuple(a, b));
            ends.add(new Tuple(b, a));
        }
        int count = 0;
        for (Tuple end : ends) {
            Tuple start = new Tuple(end.b, end.a);
            if (start.equals(starts.first())) count++;
            starts.remove(start);
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