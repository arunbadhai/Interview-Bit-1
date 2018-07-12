/*
 *  Proble link: https://www.interviewbit.com/problems/maxspprod/
 */

int Solution::maxSpecialProduct(vector<int> &A) {
    long MOD = 1000000007;
    int N = A.size();
    stack<int> val, index;
    int left[N], right[N];
    for (int i = 0; i < N; ++i) {
        if (val.empty()) {
            left[i] = 0;
            val.push(A[i]);
            index.push(i);
            continue;
        }
        while (!val.empty() && val.top() <= A[i]) {
            val.pop();
            index.pop();
        }
        if (!val.empty()) {
            left[i] = index.top();
        } else {
            left[i] = 0;
        }
        val.push(A[i]);
        index.push(i);
    }
    val = stack<int>();
    index = stack<int>();
    for (int i = N-1; i >= 0; --i) {
        if (val.empty()) {
            right[i] = 0;
            val.push(A[i]);
            index.push(i);
            continue;
        }
        while (!val.empty() && val.top() <= A[i]) {
            val.pop();
            index.pop();
        }
        if (!val.empty()) {
            right[i] = index.top();
        } else {
            right[i] = 0;
        }
        val.push(A[i]);
        index.push(i);
    }
    long maxProd = -1;
    for (int i = 0; i < N; ++i) {
        maxProd = max(maxProd, ((long)left[i]*(long)right[i])) % MOD;
    }
    return maxProd;
}
