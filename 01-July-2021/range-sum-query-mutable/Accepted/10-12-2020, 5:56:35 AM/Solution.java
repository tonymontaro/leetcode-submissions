// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
        SegTree segTree;
        public NumArray(int[] nums) {
            segTree = new SegTree(0, nums.length - 1, nums);
        }

        public void update(int i, int val) {
            segTree.pointUpdate(i, val);
        }

        public int sumRange(int i, int j) {
            return segTree.rangeSum(i, j);
        }
    
    
       class SegTree {
        int leftmost, rightmost;
        SegTree lChild, rChild;
        int sum;

        public SegTree(int leftmost, int rightmost, int[] arr) {
            if (arr.length <= 0) return;
            this.leftmost = leftmost;
            this.rightmost = rightmost;
            if (leftmost == rightmost) {
                sum = arr[leftmost];
            } else {
                int mid = (leftmost + rightmost) / 2;
                this.lChild = new SegTree(leftmost, mid, arr);
                this.rChild = new SegTree(mid + 1, rightmost, arr);
                reCalculate();
            }
        }

        public void reCalculate() {
            if (leftmost == rightmost) return;
            sum = lChild.sum + rChild.sum;
        }

        public void pointUpdate(int idx, int newVal) {
            if (idx < leftmost || idx > rightmost) return;
            if (leftmost == rightmost) sum = newVal;
            else {
                lChild.pointUpdate(idx, newVal);
                rChild.pointUpdate(idx, newVal);
            }
            reCalculate();
        }

        public int rangeSum(int l, int r) {
            if (l > rightmost || r < leftmost) return 0;

            if (l <= leftmost && r >= rightmost) return sum;

            return lChild.rangeSum(l, r) + rChild.rangeSum(l, r);
        }
    }

}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */