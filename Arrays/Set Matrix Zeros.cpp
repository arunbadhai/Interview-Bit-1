/*
 *  Problem link: https://www.interviewbit.com/problems/set-matrix-zeros/
 */

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int M = A.size(), N = A[0].size();
    int rows[M], cols[N];
    for (int i = 0; i < M; ++i)
        rows[i] = 1;
    for (int j = 0; j < N; ++j)
        cols[j] = 1;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (A[i][j] == 0) {
                rows[i] = 0;
                cols[j] = 0;
            }
        }
    }
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = rows[i]*cols[j];
        }
    }
}
