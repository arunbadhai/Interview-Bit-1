/*
 *  Problem link: https://www.interviewbit.com/problems/merge-intervals/
 */

/*
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int N = intervals.size();
    int start = -1, end = -1;
    for (int i = 0; i < N; ++i) {
        if (start == -1 && newInterval.start <= intervals[i].end) {
            start = i;
        }
        if (end == -1 && newInterval.end  <= intervals[i].end) {
            end = i;
        }
    }
    if (start == -1) {
        intervals.push_back(newInterval);
        return intervals;
    }
    if (start == end && newInterval.end < intervals[start].start) {
        intervals.insert(intervals.begin()+start, newInterval);
        return intervals;
    }
    intervals[start].start = min(intervals[start].start, newInterval.start);
    if (end == -1)
        end = N;
    if (end < N && newInterval.end >= intervals[end].start) {
        intervals[start].end = max(intervals[start].end, intervals[end].end);
        ++end;
    } else
        intervals[start].end = max(intervals[end-1].end, newInterval.end);
    intervals.erase(intervals.begin()+start+1, intervals.begin()+end);
    return intervals;
}
