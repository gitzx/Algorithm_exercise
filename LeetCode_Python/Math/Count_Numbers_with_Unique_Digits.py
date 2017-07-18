'''
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:

Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, 
excluding [11,22,33,44,55,66,77,88,99])
'''

'''
f(k) = 长度为k的不重复数位的数字个数。
f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2) [首个因数是9，因为数字不能从0开始].
'''

class Solution(object):
	def countNumbersWithUniqueDigits(self, n):
		nums = [9]
		for x in range(9, 0, -1):
			nums += nums[-1] * x,
		return sum(nums[:n]) + 1
