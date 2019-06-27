// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

// You are given a target value to search. If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.

// Your algorithm's runtime complexity must be in the order of O(log n).

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

package algos0033

func search(nums []int, target int) int {
	rotated := indexOfMin(nums)
	size := len(nums)
	left, right := 0, size-1
	for left <= right {
		mid := (left + right) / 2
		rotatedMid := (mid + rotated) % size
		switch {
		case nums[rotatedMid] < target:
			left = mid + 1
		case target < nums[rotatedMid]:
			right = mid - 1
		default:
			return rotatedMid
		}
	}
	return -1
}

func indexOfMin(nums []int) int {
	left, right := 0, len(nums)-1
	for left < right {
		mid := (left + right) / 2
		if nums[right] < nums[mid] {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return left
}
