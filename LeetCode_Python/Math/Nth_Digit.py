'''
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
'''

'''
1   1-9    : 9 * 1
2   10-99   : 90 * 2      
3   100-999  : 900 * 3
4   1000-9999
5   10000-99999
6   100000-999999
7   1000000-9999999
8   10000000-99999999
9   100000000-99999999
'''

class Solution(object):
	def findNthDigit(self, n):
		cnt, length, start = 9, 1, 1
		while n > cnt * length:
			n -= cnt * length
			cnt *= 10
			length += 1
			start *= 10
		idx = (n-1) % length
		strNum = str(start + (n-1) / length)
		return int(strNum[idx])
