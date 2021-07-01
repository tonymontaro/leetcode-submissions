// https://leetcode.com/problems/insert-into-a-binary-search-tree

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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        insert(root, val);
        return root;
    }
    void insert(TreeNode node, int val){
        if (val > node.val) {
            if (node.right == null)
                node.right = new TreeNode(val);
            else
                insert(node.right, val);
        } else {
            if (node.left == null)
                node.left = new TreeNode(val);
            else
                insert(node.left, val);
        }
    }
}