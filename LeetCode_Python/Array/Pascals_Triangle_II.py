'''
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

'''

class Solution(object):
	def getRow(self, rowIndex):
		if rowIndex < 0:
			return None
		nums = [1]
		for i in range(1, rowIndex + 1):
			if len(nums) >= 2:
				for j in range(len(nums)-2, -1, -1):
					nums[j+1] = nums[j] + nums[j+1]
			nums.append(1)
		return nums

if __name__ == '__main__':
	result = Solution().getRow(4)
	print result  # [1, 4, 6, 4, 1]