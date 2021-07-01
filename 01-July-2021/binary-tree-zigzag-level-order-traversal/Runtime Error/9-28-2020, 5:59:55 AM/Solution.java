// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        List<TreeNode> cur = new ArrayList<>();
        cur.add(root);
        int dir = 0;
        while (!cur.isEmpty()) {
            List<TreeNode> newCur = new ArrayList<>();
            List<Integer> resArr = new ArrayList<>();
            for (int i = cur.size() - 1; i >= 0; i--) {
                resArr.add(cur.get(cur.size() - i - 1).val);
                TreeNode node = cur.get(i);
                if (dir == 0) {
                    if (node.right != null) newCur.add(node.right);
                    if (node.left != null) newCur.add(node.left);
                } else {
                    if (node.left != null) newCur.add(node.left); 
                    if (node.right != null) newCur.add(node.right);
                }
            }
            res.add(resArr);
            cur = newCur;

            dir = (dir + 1) % 2;
        }
        return res;
    }
}