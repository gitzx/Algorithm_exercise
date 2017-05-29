'''
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

'''

class Solution(object):
	def threeSum(self, nums):
		nums.sort()
		result = []
		length = len(nums)
		if length < 3:
			return result
		for i in range(0, length -2):
			if i > 0  and nums[i] == nums[i-1]:
				continue
			target = -1 * nums[i]
			left, right = i+1, length - 1
			while left < right:
				if nums[left] + nums[right] == target:
					result.append([nums[i], nums[left], nums[right]])
					right -= 1
					left += 1
					while left < right and nums[left] == nums[left-1]:
						left += 1
					while left < right and nums[right] == nums[right + 1]:
						right -= 1
				elif nums[left] + nums[right] > target:
					right -= 1
				else:
					left += 1
		return result

if __name__ == '__main__':
	nums = [-1, 0, 1, 2, -1, -4]
	result = Solution().threeSum(nums)
	print result  # [[-1, -1, 2], [-1, 0, 1]]