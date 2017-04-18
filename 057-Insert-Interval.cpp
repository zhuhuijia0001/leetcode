/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
	int findStartBound(vector<Interval>& intervals, int val) {
		int low = 0;
		int high = intervals.size();

		while (low < high) {
			int mid = low + (high - low) / 2;

			if (intervals[mid].start <= val) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}

		return low - 1;
	}

	int findEndBound(vector<Interval> &intervals, int val) {
		int low = 0;
		int high = intervals.size();

		while (low < high) {
			int mid = low + (high - low) / 2;

			if (intervals[mid].end < val) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}

		return high;
	}

public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        
		int start = findStartBound(intervals, newInterval.end);
		int end = findEndBound(intervals, newInterval.start);

		if (start >= end) {
			for (int i = end; i < start; i++) {
				newInterval.start = intervals[i].start < newInterval.start ? intervals[i].start : newInterval.start;
				newInterval.end = intervals[i].end > newInterval.end ? intervals[i].end : newInterval.end;
			}

            intervals.erase(intervals.begin() + end, intervals.begin() + start);
            
			intervals[end].start = intervals[end].start < newInterval.start ? intervals[end].start : newInterval.start;
			intervals[end].end = intervals[end].end > newInterval.end ? intervals[end].end : newInterval.end;
		} else {
			intervals.insert(intervals.begin() + end, newInterval);
		}
        
        return intervals;
    }
};