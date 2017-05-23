# -*- coding: utf-8 -*-

'''
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

'''

class Solution(object):
	# dp
	def minimumTotal(self, triangle):
		"""
        :type triangle: List[List[int]]
        :rtype: int
        """
		if len(triangle) == 0 : 
			return 0

		res = [0 for i in range(len(triangle))]
		res[0] = triangle[0][0]
		for i in range(1, len(triangle)):
			for j in range(len(triangle[i])-1, -1, -1):
				if j == len(triangle[i]) -1:
					res[j] = res[j-1] + triangle[i][j]
				elif j == 0:
					res[j] = res[j] + triangle[i][j]
				else:
					res[j] = min(res[j-1], res[j]) + triangle[i][j]
		return min(res)

if __name__ == '__main__':
	triangle = [[2], [3,4], [6,5,7], [4,1,8,3]]
	result = Solution().minimumTotal(triangle)
	print result  # 11