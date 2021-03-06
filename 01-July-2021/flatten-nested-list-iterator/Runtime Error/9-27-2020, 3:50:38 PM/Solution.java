// https://leetcode.com/problems/flatten-nested-list-iterator

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {
    Stack<NestedInteger> stack;
    public NestedIterator(List<NestedInteger> nestedList) {
        stack = new Stack<>();
        addToStack(nestedList);
    }

    void addToStack(List<NestedInteger> nestedList) {
        int sz = nestedList.size();
        for (int i = sz - 1; i >= 0; i--) stack.add(nestedList.get(i));
    }

    @Override
    public Integer next() {
        while (!stack.peek().isInteger()) {
           addToStack(stack.pop().getList()); 
        }
        return stack.pop().getInteger();
    }

    @Override
    public boolean hasNext() {
        return stack.size() > 0;
    }
}
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */