/*
 *  Problem link: https://www.interviewbit.com/problems/spiral-order-matrix-i/
 */

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> spiral;
    int v1 = 0, v2 = A.size()-1, h1 = 0, h2 = A[0].size()-1, d = 0;
    while (v1 <= v2 && h1 <= h2) {
        if (d == 0) {
            for (int i = h1; i <= h2; ++i)
                spiral.push_back(A[v1][i]);
            ++v1;
        } else if (d == 1) {
            for (int i = v1; i <= v2; ++i)
                spiral.push_back(A[i][h2]);
            --h2;
        } else if (d == 2) {
            for (int i = h2; i >= h1; --i)
                spiral.push_back(A[v2][i]);
            --v2;
        } else {
            for (int i = v2; i >= v1; --i)
                spiral.push_back(A[i][h1]);
            ++h1;
        }
        d = (d+1)%4;
    }
    return spiral;
}
