'''
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

'''

class Solution(object):
	def fourSum(self, nums, target):
		result = []
		nums.sort()
		for i in range(0, len(nums) - 3):
			for j in range(i+1, len(nums) - 2):
				p = j + 1
				q = len(nums) -1
				while p != q:
					summer = nums[i] + nums[j] + nums[p] + nums[q]
					if summer == target:
						tempList = [nums[i], nums[j], nums[p], nums[q]]
						if tempList not in result:
							result.append(tempList)
						p += 1
					elif summer > target:
						q -= 1
					else:
						p += 1
		return result

if __name__ == '__main__':
	nums = [1, 0, -1, 0, -2, 2]
	result = Solution().fourSum(nums, 0)
	print result  # [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]