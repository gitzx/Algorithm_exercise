'''
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, 
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.


Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, 
then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

'''

class Solution(object):
	# two points
    def sortColors(self, nums):
		left = 0
		right = len(nums)-1
		idx = 0
		while idx <= right:
			if nums[idx] == 0:
				nums[idx], nums[left] = nums[left], nums[idx]
				left += 1
				idx += 1
			elif nums[idx] == 2:
				nums[idx], nums[right] = nums[right], nums[idx]
				right -= 1
			else:
				idx += 1

if __name__ == '__main__':
	nums = [1,2,1,2,0,0,1,2]
	Solution().sortColors(nums)
	print nums  # [0, 0, 1, 1, 1, 2, 2, 2]