'''
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
It doesn't matter what you leave beyond the new length.

'''


class Solution(object):
	def removeDuplicateFromSortedArray(self, nums):
		if len(nums) <= 2:
			return len(nums), nums
		count = 0
		oneElementCount = 0
		for i in range(len(nums)-1):
			if nums[i] == nums[i+1] and oneElementCount < 1:
				oneElementCount += 1
				count += 1
				nums[count] = nums[i+1] 
			elif nums[i] != nums[i+1]:
				oneElementCount = 0
				count += 1
				nums[count] = nums[i+1]
		return count + 1, nums[0:count+1]

if __name__ == '__main__':
	nums = [1,1,1,2,2,3]
	result = Solution().removeDuplicateFromSortedArray(nums)
	print result    #(5, [1, 1, 2, 2, 3])




