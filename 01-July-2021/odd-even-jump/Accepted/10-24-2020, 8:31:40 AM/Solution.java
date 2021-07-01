// https://leetcode.com/problems/odd-even-jump

class Solution {
    // O(nlogn) time | O(n) space
    public int oddEvenJumps(int[] arr) {
        int n = arr.length;
        int[][] dp = new int[n][2];
        dp[n - 1] = new int[]{1, 1};
        int ans = 1;
        TreeSet<Tuple> seen = new TreeSet<>();
        TreeSet<Tuple> negSeen = new TreeSet<>();
        seen.add(new Tuple(arr[n - 1], n - 1));
        negSeen.add(new Tuple(arr[n - 1], -(n - 1)));

        for (int i = n - 2; i >= 0; i--) {
            int num = arr[i];
            Tuple pos = new Tuple(num, i);
            Tuple neg = new Tuple(num, -i);
            Tuple higher = seen.ceiling(pos);
            Tuple lower = negSeen.floor(neg);
//            out.pp(i, num, higher, lower);
            int high = higher == null ? 0 : dp[higher.b][1];
            int low = lower == null ? 0 : dp[-lower.b][0];
            ans += high;
            dp[i] = new int[]{high, low};
            seen.add(pos);
            negSeen.add(neg);
        }
//        out.println(dp);

        return ans;
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