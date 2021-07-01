// https://leetcode.com/problems/fancy-sequence

class Fancy {
    int idx = 0;
    int mx = 100001;
    LazyTree lazy;
    public Fancy() {
        lazy = new LazyTree();
        lazy.build(1, 0, mx);
    }

    public void append(int val) {
        int type = 3;
        lazy.update(1, 0, mx, idx, idx, 3, val);
        idx++;
    }

    public void addAll(int inc) {
        lazy.update(1, 0, mx, 0, idx,  1, inc);
    }

    public void multAll(int m) {
        lazy.update(1, 0, mx, 0, idx, 2, m);
    }

    public int getIndex(int i) {
        if (i >= idx) return -1;
        return (int)lazy.query(1, 0, mx, i, i);
    }

    class LazyTree {
    int MAXN = 100001;
    long[] segTree = new long[MAXN];
    long[] lazyAdd = new long[MAXN];
    long[] lazyMult = new long[MAXN];
    long[] realLazy = new long[MAXN];
    long[] a = new long[MAXN];
    long mod = 1000000007;
    void refresh(int node) {
        lazyAdd[2*node] = (lazyAdd[2*node]*lazyMult[node])%mod;
        lazyAdd[2*node+1] = (lazyAdd[2*node+1]*lazyMult[node])%mod;

        lazyMult[2*node] = (lazyMult[2*node]*lazyMult[node])%mod;
        lazyMult[2*node+1] = (lazyMult[2*node+1]*lazyMult[node])%mod;

        lazyAdd[2*node] = (lazyAdd[2*node]+lazyAdd[node])%mod;
        lazyAdd[2*node+1] = (lazyAdd[2*node+1]+lazyAdd[node])%mod;
    }
    void update(int node, int left, int right, int segLeft, int segRight, int type, long value) {
        if(realLazy[node]>0) {
            segTree[node] = ((right-left+1)*realLazy[node])%mod;
            if(left!=right) {
                realLazy[2*node] = realLazy[2*node+1] = realLazy[node];
                lazyMult[2*node] = lazyMult[2*node+1] = 1;
                lazyAdd[2*node] = lazyAdd[2*node+1] = 0;
            }
            realLazy[node] = 0;
        }
        if(lazyAdd[node]!=0 || lazyMult[node]!=1) {
            segTree[node] = (segTree[node]*lazyMult[node])%mod;
            segTree[node] = (segTree[node]+(lazyAdd[node]*(right-left+1))%mod)%mod;
            if(left!=right)
                refresh(node);
            lazyMult[node] = 1;
            lazyAdd[node] = 0;
        }
        if(left>segRight || right<segLeft)
            return;
        if(left>=segLeft && right<=segRight) {
            if(type==1) {
                segTree[node] = (segTree[node]+((right-left+1)*value)%mod)%mod;
                if(left!=right) {
                    lazyAdd[2*node] = (lazyAdd[2*node]+value)%mod;
                    lazyAdd[2*node+1] = (lazyAdd[2*node+1]+value)%mod;
                }
            }
            else if(type==2) {
                segTree[node] = (segTree[node]*value)%mod;
                if(left!=right) {
                    lazyAdd[2*node] = (lazyAdd[2*node]*value)%mod;
                    lazyAdd[2*node+1] = (lazyAdd[2*node+1]*value)%mod;
                    lazyMult[2*node] = (lazyMult[2*node]*value)%mod;
                    lazyMult[2*node+1] = (lazyMult[2*node+1]*value)%mod;
                }
            }
            else if(type==3) {
                segTree[node] = (value*(right-left+1))%mod;
                if(left!=right) {
                    realLazy[2*node] = realLazy[2*node+1] = value;
                    lazyAdd[2*node] = lazyAdd[2*node+1] = 0;
                    lazyMult[2*node] = lazyMult[2*node+1] = 1;
                }
            }
        }
        else {
            int mid = (left+right)>>1;
            update(2*node, left, mid, segLeft, segRight, type, value);
            update(2*node+1, mid+1, right, segLeft, segRight, type, value);
            segTree[node] = (segTree[2*node]+segTree[2*node+1])%mod;
        }
    }
    long query(int node, int left, int right, int segLeft, int segRight) {
        if(realLazy[node]!=0) {
            segTree[node] = ((right-left+1)*realLazy[node])%mod;
            if(left!=right) {
                realLazy[2*node] = realLazy[2*node+1] = realLazy[node];
                lazyMult[2*node] = lazyMult[2*node+1] = 1;
                lazyAdd[2*node] = lazyAdd[2*node+1] = 0;
            }
            realLazy[node] = 0;
        }
        if(lazyAdd[node]!=0 || lazyMult[node]!=1) {
            segTree[node] = (segTree[node]*lazyMult[node])%mod;
            segTree[node] = (segTree[node]+(lazyAdd[node]*(right-left+1))%mod)%mod;
            if(left!=right)
                refresh(node);
            lazyMult[node] = 1;
            lazyAdd[node] = 0;
        }
        if(left>segRight || right<segLeft)
            return 0;
        if(left>=segLeft && right<=segRight)
            return segTree[node];
        else {
            int mid = (left+right)/2;
            return (query(2*node, left, mid, segLeft, segRight)+
                    query(2*node+1, mid+1, right, segLeft, segRight))%mod;
        }
    }
    void build(int node, int left, int right) {
        if(left==right) {
            segTree[node] = a[left];
            lazyMult[node] = 1;
            lazyAdd[node] = realLazy[node] = 0;
        }
        else {
            int mid = (left+right)/2;
            build(2*node, left, mid);
            build(2*node+1, mid+1, right);
            segTree[node] = (segTree[2*node]+segTree[2*node+1])%mod;
            realLazy[node] = lazyAdd[node] = 0;
            lazyMult[node] = 1;
        }
    }
}

}

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy obj = new Fancy();
 * obj.append(val);
 * obj.addAll(inc);
 * obj.multAll(m);
 * int param_4 = obj.getIndex(idx);
 */