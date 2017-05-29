'''
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

'''

import collections
class Solution(object):
	# dict cnt
	def subarraySum(self, nums, k):
		ans = sums = 0
		cnt = collections.Counter()
		for num in nums:
			cnt[sums] += 1
			sums += num
			ans += cnt[sums-k]
		return ans

if __name__ == '__main__':
	nums = [1,1,1,2,3,4,5]
	result = Solution().subarraySum(nums, 3)
	print result   # 3