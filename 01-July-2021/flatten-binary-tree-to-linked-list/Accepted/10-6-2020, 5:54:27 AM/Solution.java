// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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
    public void flatten(TreeNode root) {
        call(root);
    }

    TreeNode call(TreeNode node) {
        if (node == null) return null;
        TreeNode left = call(node.left);
        TreeNode right = call(node.right);
        TreeNode l = node.left;
        TreeNode r = node.right;
        if (l != null) {
            node.right = l;
            left.right = r;
            node.left = null;
            return r == null ? left : right;
        }
        return r == null ? node : right;
    }
}