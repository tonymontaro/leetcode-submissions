// https://leetcode.com/problems/largest-values-from-labels

class Solution {
    public int largestValsFromLabels(int[] values, int[] labels, int num_wanted, int use_limit) {
        HashMap<Integer, Item> items = new HashMap<>();
        int n = labels.length;
        for (int i = 0; i < n; i++) {
            int label = labels[i];
            if (!items.containsKey(label)) items.put(label, new Item(label, use_limit));
            items.get(label).add(values[i]);
        }
        TreeSet<Item> set = new TreeSet<>();
        for (Item item: items.values()) set.add(item);
        int total = 0;
        while (!set.isEmpty() && num_wanted > 0) {
            Item last = set.pollLast();
            if (last.isValid())
                total += last.get();
            if (last.isValid())
                set.add(last);
            num_wanted--;
        }

        return total;
    }

    class Item implements Comparable<Item> {
        public int label;
        public int limit;
        TreeSet<Integer> elements;

        public Item(int label, int limit) {
            this.label = label;
            this.limit = limit;
            this.elements = new TreeSet<>();
        }

        public void add(int num) {
            elements.add(num);
        }

        public Integer get() {
            limit--;
            return elements.pollLast();
        }

        public boolean isValid() {
            return limit > 0 && !elements.isEmpty();
        }

        public int getTop() {
            if (elements.isEmpty()) return Integer.MIN_VALUE;
            return elements.last();
        }

        @Override
        public int compareTo(Item o) {
            return Integer.compare(this.getTop(), o.getTop());
        }

        @Override
        public String toString() {
            return label + ": " + getTop();
        }
    }

}