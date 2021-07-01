// https://leetcode.com/problems/product-of-the-last-k-numbers

 class ProductOfNumbers {
        List<Integer> prefix;
        int n = 0;
        int lastZero = -1;
        public ProductOfNumbers() {
            prefix = new ArrayList<>();
            prefix.add(1);
        }

        public void add(int num) {
            if (lastZero == n)
                prefix.add(num);
            else
                prefix.add(prefix.get(n) * num);
            n++;
            if (num == 0)
                lastZero = n;
        }

        public int getProduct(int k) {
            int last = n - k;
            if (lastZero > last) return 0;
            int divisor = prefix.get(last);
            if (last == lastZero) divisor = 1;
            return prefix.get(n) / divisor;
        }
    }

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */