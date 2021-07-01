// https://leetcode.com/problems/split-two-strings-to-make-palindrome

class Solution {
    public boolean checkPalindromeFormation(String a, String b) {
        return helper(a, b) || helper(b, a);
    }

    boolean helper(String a, String b) {
        int l = 0;
        int r = a.length() - 1;
        while (l < r) {
            if (b.charAt(l) != a.charAt(r))
                return check(l, r, a) || check(l, r, b);
            l++;
            r--;
        }
        return true;
    }

    boolean check(int l, int r, String a) {
        while (l < r) {
            if (a.charAt(l) != a.charAt(r)) return false;
            l++;
            r--;
        }
        return true;
    }
}
// "aejbaalflrmkswrydwdkdwdyrwskmrlfqizjezd"
// "uvebspqckawkhbrtlqwblfwzfptanhiglaabjea"