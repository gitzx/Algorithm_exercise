// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

package algos0034

func searchRange(nums []int, target int) []int {
	index := binarySearch(nums, target)
	if index == -1 {
		return []int{-1, -1}
	}
	first := index
	for {
		f := binarySearch(nums[:first], target)
		if f == -1 {
			break
		}
		first = f
	}
	last := index
	for {
		l := binarySearch(nums[last+1:], target)
		if l == -1 {
			break
		}
		last += l + 1
	}
	return []int{first, last}
}

func binarySearch(nums []int, target int) int {
	left, right := 0, len(nums)-1
	for left <= right {
		mid := (left + right) / 2
		switch {
		case nums[mid] < target:
			left = mid + 1
		case nums[mid] > target:
			right = mid - 1
		default:
			return mid
		}
	}
	return -1
}
