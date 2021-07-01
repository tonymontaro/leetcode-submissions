// https://leetcode.com/problems/pascals-triangle

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 1; i < numRows + 1; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < i; j++) {
                if (j == 0 || j == i - 1) row.add(1);
                else {
                    List<Integer> prev = res.get(i - 2);
                    row.add(prev.get(j - 1) + prev.get(j));
                }
            }
            res.add(row);
        }

        return res;
    }
}