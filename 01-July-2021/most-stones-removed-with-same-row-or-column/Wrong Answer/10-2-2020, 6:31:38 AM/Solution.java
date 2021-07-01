// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

class Solution {

    public int removeStones(int[][] stones) {
        HashMap<Integer, List<Tuple>> xs = new HashMap<>();
        HashMap<Integer, List<Tuple>> ys = new HashMap<>();
        for (int[] s : stones) {
            Tuple stone = new Tuple(1, s[0], s[1]);
            if (xs.containsKey(s[0])) {
                for (Tuple node: xs.get(s[0])) node.addColMate(stone);
            } else xs.put(s[0], new ArrayList<>());
            if (ys.containsKey(s[1])) {
                for (Tuple node: ys.get(s[1])) node.addRowMate(stone);
            } else ys.put(s[1], new ArrayList<>());
            xs.get(s[0]).add(stone);
            ys.get(s[1]).add(stone);
        }
        TreeSet<Tuple> set = new TreeSet<>();
        for (int k: xs.keySet()) if(xs.get(k).size() > 1) set.addAll(xs.get(k));
        int ans = 0;
        while (!set.isEmpty()) {
            Tuple first = set.pollFirst();
            if (first.a < 2) continue;
            ans++;
            for (Tuple node : xs.get(first.b)) {
                set.remove(node);
                node.a--;
                if (node.a >= 2) set.add(node);
            }
            for (Tuple node : ys.get(first.c)) {
                set.remove(node);
                node.a--;
                if (node.a >= 2) set.add(node);
            }
        }

        return ans;
    }

    static class Tuple implements Comparable<Tuple> {
        int a;
        int b;
        int c;
        List<Tuple> rowMates = new ArrayList<>();
        List<Tuple> colMates = new ArrayList<>();

        public Tuple(int a, int b) {
            this.a = a;
            this.b = b;
            this.c = 0;
        }
        public Tuple(int connected, int x, int y) {
            this.a = connected;
            this.b = x;
            this.c = y;
        }

        public void addRowMate(Tuple other) {
            rowMates.add(other);
            other.rowMates.add(this);
            this.a++;
            other.a++;
        }

        public void addColMate(Tuple other) {
            colMates.add(other);
            other.colMates.add(this);
            this.a++;
            other.a++;
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