// https://leetcode.com/problems/kth-smallest-element-in-a-bst

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int kth = -1;
    int k;
    public int kthSmallest(TreeNode root, int k) {
        this.k = k;
        solve(root, 0);
        return kth;
    }

    int solve(TreeNode node, int count) {
        if (node == null) return count;
        int left = solve(node.left, count);
        if (kth > -1) return left;
        if (left + 1 == k) {
            kth = node.val;
            return left;
        }
        return solve(node.right, left + 1);
    }
}