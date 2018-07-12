/*
 *  Problem link: https://www.interviewbit.com/problems/arraybug/
 */

vector<int> Solution::rotateArray(vector<int> &A, int B) {
    vector<int> ret;
    B %= A.size();
    for (int i = 0; i < A.size() - B; i++) {
        ret.push_back(A[i + B]);
    }
    for (int i = 0; i < B; ++i) {
        ret.push_back(A[i]);
    }
    return ret;
}
