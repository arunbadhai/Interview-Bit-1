/*
 *  Problem link: https://www.interviewbit.com/problems/find-duplicate-in-array/
 */

int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector <bool> v(A.size(), true);
    for(int i = 0; i < A.size(); i++){
        if(v[A[i]])
            v[A[i]] = false;
        else
            return A[i];
    }
    return -1;
}
