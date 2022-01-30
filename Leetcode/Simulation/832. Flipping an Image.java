class Solution {
    private int[][] Helper(int[][] image) {
        int k = image[0].length;
        for (int i = 0; i < image.length; i++) {
            for (int j = 0; j < k/2; j++) {
                int temp = image[i][j] > 0 ? 0 : 1;
                image[i][j] = image[i][k - j - 1] > 0 ? 0 : 1;
                image[i][k - j - 1] = temp;
            }
        }
        if (k % 2 == 1) {
            for (int i = 0; i < image.length; i++) {
                image[i][k/2] = 1 - image[i][k/2];
            }
        }
        return image;
    }
    public int[][] flipAndInvertImage(int[][] image) {
        return Helper(image);
    }
}