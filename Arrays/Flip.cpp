/*
 *  Problem link: https://www.interviewbit.com/problems/flip/
 */

vector<int> Solution::flip(string A) {
    vector<int> sol;
    sol.reserve(2);
    int N = A.length();
    int max = -1, curr = 0, start = 0, end = 0, currStart = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] == '1')
            --curr;
        else
            ++curr;
        if (curr < 0) {
            curr = 0;
            currStart = i+1;
            continue;
        }
        if (curr > max) {
            start = currStart;
            max = curr;
            end = i;
        }
    }
    if (max <= 0) {
        return sol;
    }
    sol.push_back(start+1);
    sol.push_back(end+1);
    return sol;
}
