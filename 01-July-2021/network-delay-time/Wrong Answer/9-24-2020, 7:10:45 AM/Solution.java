// https://leetcode.com/problems/network-delay-time

import java.io.*;
import java.util.*;

class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        HashMap<Integer, TreeSet<Tuple>> nodes = new HashMap<>();
        for (int i = 1; i < n + 1; i++) nodes.put(i, new TreeSet<>());
        for (int[] time : times) {
            int a = time[0], b = time[1], w = time[2];
            nodes.get(a).add(new Tuple(w, b));
        }
        boolean[] visited = new boolean[n + 1];
        visited[k] = true;
        Deque<Tuple> deque = new ArrayDeque<>();
        deque.addLast(new Tuple(0, k));
        int ans = 0;
        while (!deque.isEmpty()) {
            Tuple node = deque.pollFirst();
            int w = node.a;
            ans = Math.max(ans, w);
            int idx = node.b;
            for (Tuple child : nodes.get(idx)) {
                if (!visited[child.b]) {
                    visited[child.b] = true;
                    deque.addLast(new Tuple(w + child.a, child.b));
                }
            }
        }
        for (int i = 1; i < n + 1; i++) if (!visited[i]) return -1;

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