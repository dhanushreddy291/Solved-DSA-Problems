class Solution {
    private Map <Character, int[]> map = Map.of (
        'N', new int[]{-1, 0}, 
        'S', new int[]{1, 0}, 
        'E', new int[]{0, -1}, 
        'W', new int[]{0, 1}
    );
    public boolean isPathCrossing(String path) {
        Set <Integer> set = new HashSet<>();
        int X = 0, Y = 0, MOD = 10001; 
        set.add(0);
        for (char Direction : path.toCharArray()) {
            X += map.get(Direction)[0];
            Y += map.get(Direction)[1];
            //As Given that 1 <= path.length <= 10^4 so 10^4 can be the Max Value of X and Y and thus it may be used as a Mod Value for Hashing using a Integer Set rather than using a Set of Lists for Co-ordinates
            if (!set.add(X * MOD + Y)) return true;
        }
        return false;
    }
}