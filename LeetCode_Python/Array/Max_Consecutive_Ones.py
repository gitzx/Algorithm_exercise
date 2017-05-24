'''
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000

'''

class Solution(object):
	def maxConsecutiveOnes(self, nums):
		result = []
		lens = []
		for n in nums:
			if n == 1:
				result.append(n)
			else:
				lens.append(len(result))
				result = []
		lens.append(len(result))
		result = []
		maxLen = 0
		for l in lens:
			if l > maxLen:
				maxLen = l
		return maxLen

	def maxConsecutiveOnes2(self, nums):
		ans = cnt = 0
		for n in nums:
			if n == 1:
				cnt += 1
				ans = max(ans, cnt)
			else:
				cnt = 0
		return ans

if __name__ == '__main__':
	nums = [1,1,0,1,1,1]
	result = Solution().maxConsecutiveOnes(nums)
	print result  # 3