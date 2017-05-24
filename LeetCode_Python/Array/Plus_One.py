'''
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

 [7, 1, 6, 7, 9, 4]
'''

class Solution(object):
	def plusOne(self, digits):
		carry = 1
		for i in range(len(digits)-1, -1, -1):
			newCarry = digits[i] + carry
			if newCarry >= 10:
				digits[i] = newCarry % 10
				carry = newCarry / 10
			else:
				digits[i] = newCarry
				return digits
		if carry > 0:
			digits.insert(0, carry)
			return digits

if __name__ == '__main__':
	digits = [1,2,9,9,9]
	result = Solution().plusOne(digits)
	print result # [1, 3, 0, 0, 0]
