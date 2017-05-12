'''
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. 
It doesn't matter what you leave beyond the new length.

'''

class Solution(object):
	def removeDuplicateFromSortedArray(self, nums):
		if nums == []:
			return 0
		count = 0
		for i in range(len(nums)-1):
			if nums[i] != nums[i+1]:
				count += 1
				nums[count] = nums[i+1]
		return count + 1

if __name__ == '__main__':
	nums = [1,1,1,2,2,3,4,4,5]
	result = Solution().removeDuplicateFromSortedArray(nums)
	print result  #5
