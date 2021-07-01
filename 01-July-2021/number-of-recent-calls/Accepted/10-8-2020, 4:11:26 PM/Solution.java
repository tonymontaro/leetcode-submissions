// https://leetcode.com/problems/number-of-recent-calls

class RecentCounter {
    Deque<Integer> recentCalls = new ArrayDeque<>();
    public RecentCounter() {
    }

    public int ping(int t) {
        int last = t - 3000;
        recentCalls.addLast(t);
        while(!recentCalls.isEmpty() && recentCalls.peekFirst() < last)
            recentCalls.pollFirst();
        return recentCalls.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */