'''
Given an array of integers and an integer k, 
find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

'''

class Solution(object):
	def containsDuplicate(self, nums, k):
		newDict = dict()
	 	for i in range(len(nums)):
	 		idx = newDict.get(nums[i])
	 		if idx >= 0 and i-idx <= k:
	 			return True
	 		newDict[nums[i]] = i
	 	return False

if __name__ == '__main__':
	nums = [1,2,3,4,5,1]
	result = Solution().containsDuplicate(nums, 3)
	print result


