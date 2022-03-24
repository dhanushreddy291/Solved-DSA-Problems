class Solution {
    public int halveArray(int[] nums) {
        double ArraySum = 0, Sum = 0;
        int count = 0;
        PriorityQueue<Double> Heap = new PriorityQueue<>(Comparator.reverseOrder());
        for (int a : nums) {
            Heap.add(a/1.0);
            ArraySum += a;
        }
        ArraySum /= 2.0;
        while (Sum < ArraySum) {
            double temp = Heap.poll();
            temp /= 2.0;
            Heap.add(temp);
            Sum += temp;
            count++;
        }
        return count;
    }
}