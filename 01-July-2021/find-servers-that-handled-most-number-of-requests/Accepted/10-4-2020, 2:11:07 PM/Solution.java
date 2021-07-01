// https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests

class Solution {
    public List<Integer> busiestServers(int k, int[] arrival, int[] load) {
        TreeSet<Tuple> available = new TreeSet<>();
        Tuple[] nodes = new Tuple[k];
        for (int i = 0; i < k; i++) {
            Tuple node = new Tuple(0, i, 0);
            available.add(node);
            nodes[i] = node;
        }
        HashMap<Integer, Integer> count = new HashMap<>();
        int mx = 0;
        TreeSet<Tuple> occupied = new TreeSet<>();
        for (int i = 0; i < arrival.length; i++) {
            int time = arrival[i] + load[i];
//            out.println(occupied);
//            out.pp(time);
            while (!occupied.isEmpty() && arrival[i] >= occupied.first().a) {
                Tuple nn = occupied.pollFirst();
                nodes[nn.b].c = 0;
                available.add(nodes[nn.b]);
            }

            Tuple node = nodes[i % k];
            if (node.c == 1 && available.isEmpty()) continue;
            if (node.c == 1) {
                node = available.ceiling(node);
                if (node == null)
                    node = available.first();
            }
            available.remove(node);
            count.merge(node.b, 1, Integer::sum);
            mx = Math.max(mx, count.get(node.b));

            Tuple busyNode = new Tuple(time, node.b, 1);
            nodes[node.b].c = 1;
            occupied.add(busyNode);
//            out.println("============");
        }
//        out.println(count);
        List<Integer> res = new ArrayList<>();
        for (int key: count.keySet()) if (count.get(key) == mx) res.add(key);
        return res;
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