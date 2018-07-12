/*
 *  Problem link: https://www.interviewbit.com/problems/maximum-absolute-difference/
 */

int Solution::maxArr(vector<int> &A) {
    int N = A.size();
    int arrNetL[N], arrNetR[N];
    for (int i = 0; i < N; ++i) {
        arrNetR[i] = A[i] - i;
        arrNetL[i] = A[i] - (N-1-i);
        //cout<<arrNet[i]<<" ";
    }
    // cout<<endl;

    int minL[N], minR[N], minLPos[N], minRPos[N];
    minL[0] = arrNetL[0];
    minLPos[0] = 0;
    for (int i = 1; i < N; ++i) {
        minL[i] = min(minL[i-1], arrNetL[i]);
        if (minL[i] == minL[i-1])
            minLPos[i] = minLPos[i-1];
        else
            minLPos[i] = i;
    }

    minR[N-1] = arrNetR[N-1];
    minRPos[N-1] = N-1;
    for (int i = N-2; i >= 0; --i) {
        minR[i] = min(minR[i+1], arrNetR[i]);
        if (minR[i] == minR[i+1])
            minRPos[i] = minRPos[i+1];
        else
            minRPos[i] = i;
    }
    /* for (int i = 0; i < N; ++i) {
        cout<<minLPos[i]<<" "<<minL[i]<<" "<<minRPos[i]<<" "<<minR[i]<<endl;
    }*/
    
    int maxVal = 0;
    for (int i = 0; i < N; ++i) {
        maxVal = max(maxVal, max(abs(A[minLPos[i]] - A[i])+abs(minLPos[i] - i), abs(A[minRPos[i]] - A[i])+abs(minRPos[i] - i)));
        // cout<<maxVal<<" ";
    }
    return maxVal;
}
