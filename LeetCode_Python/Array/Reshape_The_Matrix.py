'''
In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, 
and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.

Example 2:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
Output: 
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.

Note:
The height and width of the given matrix is in range [1, 100].
The given r and c are all positive.

'''

class Solution(object):
	def matrixReshape(self, nums, r, c):
		rows = len(nums)
		cols = 0
		if type(nums[0]) == list:
			cols = len(nums[0])
		else:
			cols = 1
		if rows * cols != r *c:
			return nums
		newNums = []
		tempNums = []
		count = 0
		for i in range(rows):
			for j in range(cols):
				tempNums.append(nums[i][j])
				count += 1
				if count == c:
					newNums.append(tempNums)
					tempNums = []
					count = 0
		return newNums

	def matrixReshape2(self, nums, r, c):
		rows = len(nums)
		cols = 0
		if type(nums[0]) == list:
			cols = len(nums[0])
		else:
			cols = 1
		if rows * cols != r *c:
			return nums
		newNums = [[None]* c for i in range(r)]
		for i in range(r):
			for j in range(c):
				newNums[i][j] = nums[(i * c + j)/cols][(i * c + j) % cols]

		return newNums

	def matrixReshape3(self, nums, r, c):
		rows = len(nums)
		cols = 0
		if type(nums[0]) == list:
			cols = len(nums[0])
		else:
			cols = 1
		if rows * cols != r *c:
			return nums
		newNums = [[None]* c for i in range(r)]   #错误：[[None]*c]*r
		for i in range(r*c):
			newNums[i/c][i%c] = nums[i/cols][i%cols]

		return newNums

if __name__ == '__main__':
	nums = [[1,2,3], [4,5,6]]
	result = Solution().matrixReshape3(nums, 3, 2)
	print result  # [[1, 2], [3, 4], [5, 6]]


				



