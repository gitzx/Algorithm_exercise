// Given a collection of intervals, merge all overlapping intervals.

// Example 1:

// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
// Example 2:

// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
// NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

package algos0056

import (
	"sort"
)

func merge(intervals [][]int) [][]int {
	n := len(intervals)
	if n <= 1 {
		return intervals
	}
	sort.Slice(intervals, func(i int, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	var res [][]int
	temp := intervals[0]
	for i := 1; i < n; i++ {
		if intervals[i][0] <= temp[1] {
			temp[1] = max(intervals[i][1], temp[1])
		} else {
			res = append(res, temp)
			temp = intervals[i]
		}
	}
	res = append(res, temp)
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
