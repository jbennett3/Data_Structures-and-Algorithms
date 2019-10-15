//Programmer Name: Justin Bennett
/*Porgram Description: program takes an ordered set of intervals in a vector and inserts and merges new intervals
 and return vector with new start and end values*/
/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary). You may assume that the intervals were initially sorted according to their start times.
Example 1:  Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].
Example 2: Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. Make sure the returned intervals are also sorted.

*/
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
//Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}

};
// To be implemented
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) // To be implemented
{
	//initalize start and end values which will be manipulated later//
	int start = 0;
	int end = 0;
	/*first loop handels an insertion mainly for case 1 with adding an interval
	when new interval has a greater end value but start falls into between the orginal
	start value range and making a new end range.
	*/
	for (unsigned int i = 0; i < intervals.size(); i++)
	{
		if (newInterval.end > intervals[i].end&&newInterval.end < intervals[i + 1].end)
			if (newInterval.start > intervals[i].start&&newInterval.end > intervals[i].end)
			{
				intervals[i].end = newInterval.end;
			}
	}
	/* compares the start value of both the new interval and the orignal and sets the original
	interval's start to the minimum*/
	intervals[0].start = min(intervals[0].start, newInterval.start);
	/*since the original interval is already sorted by using the back() you can compare
	the new interval end to the largest value in the original interval
	*/
	intervals.back().end = max(intervals.back().end, newInterval.end);
	/* For loop will handle the assigning the new start and finish values for the orignial interval
	 check if the the new interval start and end are greater the oringinal and reassign the start and end values
	 handles case 2 where you have multiple multiple intervals that fall into a couple of ranges
	 where the new interval start is greater but the end is smaller or the end and the end of new interval is smaller than the start
	 but the start is greater than the end.*/
	for (unsigned int i = 0; i < intervals.size(); i++)
	{
		if (newInterval.start >= intervals[i].start&&newInterval.start <= intervals[i].end)
			start = i;
		if (newInterval.end >= intervals[i].start&&newInterval.start <= intervals[i].end)
			end = i;
	}
	/*loop through the interval with it's new values and swap the start and end values */
	intervals[start].end = intervals[end].end;
	unsigned int interval_start = start + 1;
	unsigned int interval_end = end + 1;
	for (unsigned int i = 0; i < intervals.size(); i++)
		if (interval_end < intervals.size())
			swap(intervals[interval_start++], intervals[interval_end++]);
	intervals.resize(interval_start);//resize the interval after the start and end values have been replaced //
	return intervals;
}



int main()
{
	Interval interval1(1, 3), interval2(6, 9);
	vector<Interval> intervalSet_in1 = { interval1, interval2 }; // C++11 initialization
	cout << "Interval set prior to inserting [2,5]" << endl;
	for (auto ele : intervalSet_in1) { // C++11 range loops
		cout << ele.start << " " << ele.end << endl;
	}
	vector<Interval>intervalSet_out1 = insert(intervalSet_in1, Interval(2, 5));
	cout << "Interval set after inserting [2,5]" << endl;
	for (auto ele : intervalSet_out1) {
		cout << ele.start << " " << ele.end << endl;
	}
	cout << endl;
	Interval interval3(1, 2), interval4(3, 5), interval5(6, 7), interval6(8, 10), interval7(12, 16);
	vector<Interval> intervalSet_in2 = { interval3, interval4, interval5, interval6, interval7 };
	cout << "Interval set prior to inserting [4,9]" << endl;
	for (auto ele : intervalSet_in2) { // C++11 range loops
		cout << ele.start << " " << ele.end << endl;
	}
	vector<Interval> intervalSet_out2 = insert(intervalSet_in2, Interval(4, 9));
	cout << "Interval set after inserting [4,9]" << endl;
	for (auto ele : intervalSet_out2) {
		cout << ele.start << " " << ele.end << endl;
	}
	cin.get();
	return 0;
}
