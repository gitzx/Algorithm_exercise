'''
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.

'''

class Solution(object):
	def containsDuplicate(self, nums):
		hash = {}
		for i in range(len(nums)):
			if nums[i] in hash:
				return  True
			hash[i] = nums[i]
		return False

	def containsDuplicate2(self, nums):
		newSet = set()
		for num in nums:
			if num in newSet:
				return True
			newSet.add(num)
		return False

	def containsDuplicate3(self, nums):
		return len(set(nums)) != len(nums)

	def containsDuplicate4(self, nums):
		nums.sort()
		for i in range(len(nums)-1):
			if (nums[i] == nums[i+1]):
				return True
		return False

if __name__ == '__main__':
	nums = [1,2,3,4,5,1]
	result = Solution().containsDuplicate(nums)
	print result  #True