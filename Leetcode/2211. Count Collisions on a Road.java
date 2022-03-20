class Solution {
    public int countCollisions(String directions) {
        int N = directions.length(), i = 0, collisions = 0;
        while (i < N && directions.charAt(i) == 'L') i++;
        while (i < N) {
            if (directions.charAt(i) == 'L') collisions++;
            else if (i < N - 1) {
                if (directions.charAt(i) == 'R') {
                    int similarCars = 0;
                    while (i < N - 1 && directions.charAt(i + 1) == 'R') {
                        similarCars++;
                        i++;
                    }
                    if (i < N - 1) {
                        if (directions.charAt(i + 1) == 'S') collisions += 1 + similarCars;
                        else collisions += 2 + similarCars;
                        i++;
                    }
                }
            }
            i++;
        }
        return collisions;
    }
}