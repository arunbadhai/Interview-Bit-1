/*
 *  Problem link: https://www.interviewbit.com/problems/wave-array/
 */

vector<int> Solution::wave(vector<int> &A) {
    int N = A.size();
    sort(A.begin(), A.end());
    for (int i = 1; i < N; i += 2) {
        A[i] += A[i-1];
        A[i-1] = A[i] - A[i-1];
        A[i] -= A[i-1];
    }
    return A;
}
