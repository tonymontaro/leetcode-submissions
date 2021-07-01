// https://leetcode.com/problems/serialize-and-deserialize-bst

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

        // Encodes a tree to a single string.
        public String serialize(TreeNode root) {
            StringBuilder rs = new StringBuilder();
            serializeHelper(root, rs);
            rs.deleteCharAt(rs.length() - 1);
            return rs.toString();
        }

        void serializeHelper(TreeNode node, StringBuilder rs) {
            if (node == null) {
                rs.append('n').append(",");
                return;
            }
            rs.append(node.val).append(",");
            serializeHelper(node.left, rs);
            serializeHelper(node.right, rs);
        }

        // Decodes your encoded data to tree.
        int idx;
        public TreeNode deserialize(String data) {
            String[] dat = data.split(",");
            idx = 0;
            return deserializeHelper(dat);
        }

        TreeNode deserializeHelper(String[] data) {
            String ch = data[idx++];
            if (ch.equals("n")) return null;
            TreeNode node = new TreeNode(Integer.parseInt(ch));
            node.left = deserializeHelper(data);
            node.right = deserializeHelper(data);
            return node;
        }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// String tree = ser.serialize(root);
// TreeNode ans = deser.deserialize(tree);
// return ans;