/*
* Complete the 'flippingMatrix' function below.
*
* The function is expected to return an INTEGER.
* The function accepts 2D_INTEGER_ARRAY matrix as parameter.
*/
int flippingMatrix (vector <vector<int>> matrix) {
    int n = matrix.size() / 2, Answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Answer += max(max(matrix[i][j], matrix[i][2 * n - 1 - j]), max(matrix[2 * n - 1 - i][j], matrix[2 * n - 1 - i][2 * n - 1 - j]));
        }
    }
    return Answer;
}