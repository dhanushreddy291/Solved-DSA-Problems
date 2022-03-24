class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int leftPointer = 0, rightPointer = people.length - 1, rescueBoats = 0;
        while (leftPointer <= rightPointer) {
            if (people[leftPointer] + people[rightPointer] > limit) rightPointer--;
            else {
                leftPointer++;
                rightPointer--;
            }
            rescueBoats++;
        }
        return rescueBoats;
    }
}