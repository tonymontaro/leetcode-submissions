// https://leetcode.com/problems/binary-search-tree-iterator

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
class BSTIterator {
    Deque<TreeNode> deque = new ArrayDeque<>();
    public BSTIterator(TreeNode root) {
        dfs(root);
    }

    void dfs(TreeNode node) {
        if (node == null) return;
        dfs(node.left);
        deque.addLast(node);
        dfs(node.right);
    }

    /**
     * @return the next smallest number
     */
    public int next() {
        if (deque.isEmpty()) return -1;
        return deque.pollFirst().val;
    }

    /**
     * @return whether we have a next smallest number
     */
    public boolean hasNext() {
        return !deque.isEmpty();
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */