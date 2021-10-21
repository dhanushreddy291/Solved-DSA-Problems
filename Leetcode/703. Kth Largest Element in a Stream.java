class KthLargest {
    final PriorityQueue <Integer> Heap;
    final int K;
    public KthLargest(int k, int[] nums) {
        this.K = k;
        Heap = new PriorityQueue<>();
        for (int num : nums) Heap.add(num);
        int N = nums.length;
        while (N-- > k) Heap.remove();
    }
    
    public int add(int val) {
        if (Heap.size() > 0) {
            int Peek = Heap.peek();
            if (Peek >= val) {
                if (Heap.size() < K) {
                    Heap.add(val);
                    return Heap.peek();
                }
                else
                return Peek;
            }
            else {
                Heap.add(val);
                if (Heap.size() > K)
                    Heap.remove();
                return Heap.peek();
            }
        }
        else {
            Heap.add(val);
            return val;
        }
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */