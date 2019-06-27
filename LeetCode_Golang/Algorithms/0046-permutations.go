// Given a collection of distinct integers, return all possible permutations.

// Example:

// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

package algos0046

func permute(nums []int) [][]int {
	n := len(nums)
	vector := make([]int, n)
	taken := make([]bool, n)
	var ans [][]int
	makePermute(0, n, nums, vector, taken, &ans)
	return ans
}

func makePermute(cur, n int, nums, vector []int, taken []bool, ans *[][]int) {
	if cur == n {
		tmp := make([]int, n)
		copy(tmp, vector)
		*ans = append(*ans, tmp)
		return
	}
	for i := 0; i < n; i++ {
		if !taken[i] {
			taken[i] = true
			vector[cur] = nums[i]
			makePermute(cur+1, n, nums, vector, taken, ans)
			taken[i] = false
		}
	}
}
