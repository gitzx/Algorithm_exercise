'''
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,

Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

'''

class Solution(object):
	def generate(self, numRows):
		nums = [[1] * (i+1) for i in range(numRows)] 
		if numRows <= 2:
			return nums
		for i in range(2, numRows):
			for j in range(1, i):
				nums[i][j] =  nums[i-1][j-1] + nums[i-1][j]
		return nums

if __name__ == '__main__':
	result = Solution().generate(5)
	print result  # [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]