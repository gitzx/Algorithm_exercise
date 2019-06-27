// Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

// You may assume the integer does not contain any leading zero, except the number 0 itself.

// Example 1:

// Input: [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Example 2:

// Input: [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.

package algos0066

func plusOne(digits []int) []int {
	lenght := len(digits)
	if lenght == 0 {
		return []int{1}
	}
	digits[lenght-1]++
	for i := lenght - 1; i > 0; i-- {
		if digits[i] < 10 {
			break
		}
		digits[i] -= 10
		digits[i-1]++
	}
	if digits[0] >= 10 {
		digits[0] -= 10
		digits = append([]int{1}, digits)
	}
	return digits
}
