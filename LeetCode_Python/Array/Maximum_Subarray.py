'''
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

'''

class Solution(object):
	def maxSubArray(self, nums):
		maxSum = 0
		tempSum = 0
		for n in nums:
			tempSum = max(tempSum + n, n)
			maxSum = max(maxSum, tempSum)
		return maxSum

	def maxSubArray2(self, nums):
		maxSum = 0
		tempSum = 0
		for n in nums:
			if tempSum < 0:
				tempSum = 0
			tempSum = tempSum + n
			maxSum = max(tempSum, maxSum)
		return maxSum

	# dp
	def maxSubArray3(self, nums):
		maxSum = nums[0]
		tempSum = [0 for i in range(len(nums))]
		tempSum[0] = nums[0]
		for i in range(1, len(nums)):
			tempSum[i] = max(nums[i], tempSum[i-1] + nums[i])
			maxSum = max(maxSum, tempSum[i])
		return maxSum

if __name__ == '__main__':
	nums = [-2,1,-3,4,-1,2,1,-5,4]
	result = Solution().maxSubArray3(nums)
	print result  # 6



	