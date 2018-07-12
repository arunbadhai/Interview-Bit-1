/*
 *  Problem link: https://www.interviewbit.com/problems/add-one-to-number/
 */

vector<int> Solution::plusOne(vector<int> &A) {
    int carry = 1;
    for (int i = A.size()-1; i >= 0; --i) {
        A[i] = A[i] + carry;
        carry = A[i]/10;
        A[i] = A[i]%10;
    }
    if (carry)
        A.insert(A.begin(), carry);
    if (A[0] == 0) {
        int i;
        for (i = 1; i < A.size(); ++i) {
            if (A[i] != 0)
                break;
        }
        A.erase(A.begin(), A.begin()+i);
    }
    return A;
}
