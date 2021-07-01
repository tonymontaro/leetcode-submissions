// https://leetcode.com/problems/divisor-game

class Solution {
    public boolean divisorGame(int N) {
        boolean[] canWin = new boolean[N + 1];
        List<Integer>[] divisors = new ArrayList[N + 1];
        for (int i = 2; i < N + 1; i++) {
            divisors[i] = new ArrayList<>();
            divisors[i].add(1);
        }
        int idx = 2;
        while (idx <= N) {
            for (int i = idx + idx; i < N + 1; i += idx) divisors[i].add(idx);
            for (int div : divisors[idx]) {
                if (!canWin[idx - div]) {
                    canWin[idx] = true;
                    break;
                }
            }
            idx++;
        }

        return canWin[N];
    }
}