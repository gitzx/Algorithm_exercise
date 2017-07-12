'''
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
'''

class Solution(object):
	def titleToNumber(self, s):
		ans = 0
		for c in s:
			ans = ans * 26 + ord(c) - ord('A') + 1
		return ans
		