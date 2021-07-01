// https://leetcode.com/problems/reverse-only-letters

class Solution {
    public String reverseOnlyLetters(String S) {
        char[] arr = S.toCharArray();
        int n = arr.length;
        int l = 0;
        int r = n - 1;
        while (l < r) {
            while (l < n && !Character.isLetter(arr[l])) l++;
            while (r >=0 && !Character.isLetter(arr[r])) r--;
            if (l < r) swap(arr, l, r);
            l++;
            r--;
        }
        StringBuilder res = new StringBuilder();
        for (char ch: arr) res.append(ch);
        return res.toString();
    }

    public static char[] swap(char[] arr, int left, int right) {
        char temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        return arr;
    }
}