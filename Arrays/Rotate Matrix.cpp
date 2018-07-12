/*
 *  Problem link: https://www.interviewbit.com/problems/rotate-matrix/
 */

void Solution::rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int l = A.size();
    for (int i = 0; i < l; ++i) {
        for (int j = i+1; j < l; ++j) {
            A[i][j] += A[j][i];
            A[j][i] = A[i][j] - A[j][i];
            A[i][j] -= A[j][i];
        }
    }
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < l/2; ++j) {
            A[i][j] += A[i][l-j-1];
            A[i][l-j-1] = A[i][j] - A[i][l-j-1];
            A[i][j] -= A[i][l-j-1];
        }
    }
}
