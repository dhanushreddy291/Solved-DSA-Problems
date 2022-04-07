class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue <Integer> Heap = new PriorityQueue <Integer> (Collections.reverseOrder());
        for (int i = 0; i < stones.length; i++) {
            Heap.add(stones[i]);
        }
        while (Heap.size() > 0) {
            int A = Heap.poll();
            if (Heap.size() > 0) {
                int B = Heap.poll();
                if (A != B) Heap.add(Math.abs(A - B));
            } else return A;
        }
        return 0;
    }
}