'''
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
'''

class Solution(object):
	def addStrings(self, num1, num2):
		result = []
		carry = 0
		idx1, idx2 = len(num1), len(num2)
		while idx1 or idx2 or carry:
			digit = carry
			if idx1:
				idx -= 1
				digit += int(num1[idx1])
			if idx2:
				idx2 -= 1
				digit += int(num2[idx2])
			carry = digit > 9
			result.append(str(digit % 10))
		return ''.join(result[::-1])
		