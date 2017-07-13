'''
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
'''

class Solution(object):
	def plusOne(self, digits):
		flag = 1
		for i in range(len(digits) - 1, -1, -1):
			if digits[i] + flag == 10:
				digits[i] = 0
				flag = 1
			else:
				digits[i] = digits[i] + flag
				flag = 0
		if flag == 1:
			digits.insert(0, 1)
		return digits
		