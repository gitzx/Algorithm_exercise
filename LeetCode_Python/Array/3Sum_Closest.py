'''
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

'''

class Solution(object):
	def threeSumClosest(self, nums, target):
		nums.sort()
		mindiff = 100000
		result = None
		for i in range(len(nums)):
			left, right = i + 1, len(nums) - 1
			while left < right:
				total = nums[left] + nums[right] + nums[i]
				diff = abs(total - target)
				if result is None or diff < mindiff:
					mindiff = diff
					result = total
				if total == target:
					return total
				elif total < target:
					left += 1
				else:
					right -= 1
		return result

if __name__ == '__main__':
	nums = [-1, 2, 1, -4]
	result = Solution().threeSumClosest(nums, 1)
	print result

