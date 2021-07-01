// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[1] == o2[1]) return Integer.compare(o1[0], o2[0]);
                return Integer.compare(o1[1], o2[1]);
            }
        });
        int n = points.length;
        int idx = 0;
        int cnt = 0;
        while (idx < n) {
            int[] node = points[idx];
            while (idx < n && points[idx][0] <= node[1]) idx++;
            cnt++;
        }

        return cnt;
    }
}