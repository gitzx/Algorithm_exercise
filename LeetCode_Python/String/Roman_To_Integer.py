'''
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
'''

class Solution(object):
	def romanToInt(self, s):
		numerals = {"I": 1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
		sum = 0
		maxDigit = 1
		for i in range(len(s)-1, -1, -1):
			if numerals[s[i]] >= maxDigit:
				maxDigit = numerals[s[i]]
				sum += numerals[s[i]]
			else:
				sum -= numerals[s[i]]
		return sum


