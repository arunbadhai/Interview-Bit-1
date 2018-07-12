/*
 * Problem link: https://www.interviewbit.com/problems/pascal-triangle/
 */

vector<vector<int> > Solution::generate(int A) {
    vector<vector<int> > pascal;
    if (A < 1)
        return pascal;
    pascal.push_back(vector<int>(1, 1));
    for (int i = 1; i < A; ++i) {
        vector<int> nth;
        for (int j = 0; j <= i; ++j) {
            int temp = 0;
            if (j < i)
                temp += pascal[i-1][j];
            if (j)
                temp += pascal[i-1][j-1];
            nth.push_back(temp);
        }
        pascal.push_back(nth);
    }
    return pascal;
}
