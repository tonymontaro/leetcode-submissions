// https://leetcode.com/problems/sort-array-by-parity

class Solution {
    public int[] sortArrayByParity(int[] arr) {
        int oddIdx = arr.length - 1;
        for (int i = 0; i < arr.length; i++) {
            while (arr[i] % 2 == 1 && oddIdx > i) {
                int temp = arr[i];
                arr[i] = arr[oddIdx];
                arr[oddIdx--] = temp;
            }
        }
        return arr;
    }

}