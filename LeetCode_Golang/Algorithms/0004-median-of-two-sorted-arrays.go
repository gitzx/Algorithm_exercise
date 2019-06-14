// There are two sorted arrays nums1 and nums2 of size m and n respectively.

// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

// You may assume nums1 and nums2 cannot be both empty.

// Example 1:

// nums1 = [1, 3]
// nums2 = [2]

// The median is 2.0
// Example 2:

// nums1 = [1, 2]
// nums2 = [3, 4]

// The median is (2 + 3)/2 = 2.5

package algos

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	nums := combine(nums1, nums2)
	return medianOf(nums)
}

func combine(m []int, n []int) []int {
	lenM, i := len(m), 0
	lenN, j := len(n), 0
	res := make([]int, lenM+lenN)
	for k := 0; k < lenM+lenN; k++ {
		if i == lenM || (i < lenM && j < lenN && m[i] > n[j]) {
			res[k] = n[j]
			j++
		}
		if j == lenN || (i < lenM && j < lenN && m[i] <= n[j]) {
			res[k] = m[i]
			i++
		}
	}
	return res
}

func medianOf(nums []int) float64 {
	len := len(nums)
	if len == 0 {
		panic("长度不够")
	}
	if len/2 == 0 {
		return float64(nums[len/2])
	} else {
		return float64(nums[len/2]+nums[len/2-1]) / 2.0
	}
}
