'''
Given a list of non-negative numbers and a target integer k, 
write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, 
that is, sums up to n*k where n is also an integer.

Example 1:

Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.

Example 2:

Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.

Note:
The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
'''

class Solution(object):
	def checkSubarraySum(self, nums, k):
		length = len(nums)
		for i in range(length):
			total = nums[i]
			for j in range(i+1, length):
				total += nums[j]
				if total == k:
					return True
				if k != 0 and total % k == 0:
					return True
		return False

	#若数字a和b分别除以数字c，若得到的余数相同，那么(a-b)必定能够整除c
	def checkSubarraySum(self, nums, k):
		dmap = {0 : -1}
		total = 0
		for i, n in enumerate(nums):
			total += n
			m = total % k if k else total 
			if m not in dmap:
				dmap[m] = i
			elif dmap[m] + 1 < i:
				return True
		return False

