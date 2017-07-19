'''
Given a positive integer n, 
break it into the sum of at least two positive integers and maximize the product of those integers. 
Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.
'''

'''
观察n从2到13时的情形：

2  ->  1 * 1
3  ->  2 * 1
4  ->  2 * 2
5  ->  3 * 2
6  ->  3 * 3
7  ->  3 * 2 * 2
8  ->  3 * 3 * 2
9  ->  3 * 3 * 3
10 ->  3 * 3 * 2 * 2
11 ->  3 * 3 * 3 * 2
12 ->  3 * 3 * 3 * 3
13 ->  3 * 3 * 3 * 2 * 2

观察n从2到13时的情形：

2  ->  1 * 1
3  ->  2 * 1
4  ->  2 * 2
5  ->  3 * 2
6  ->  3 * 3
7  ->  3 * 2 * 2
8  ->  3 * 3 * 2
9  ->  3 * 3 * 3
10 ->  3 * 3 * 2 * 2
11 ->  3 * 3 * 3 * 2
12 ->  3 * 3 * 3 * 3
13 ->  3 * 3 * 3 * 2 * 2
'''

class Solution(object):
	#dp  状态转移方程：dp[x] = max(3*dp[x-3] , 2*dp[x-2])
	def integerBreak(self, n):
		if n <= 3:
			return n-1
		dp = [0] * (n+1)
		dp[2], dp[3]  = 2, 3
		for x in range(4, n + 1):
			dp[x] = max(3 * dp[x-3], 2*dp[x-2])
		return dp[n]

	def integerBreak2(self, n):
		div = n / 3
		if div <= 1:
			return (n / 2) * (n/2 + n % 2)
		mod = n % 3
		if mod == 0:
			return 3 ** div
		elif mod == 1:
			return 3 ** (div - 1) * 4
		elif mod == 2:
			return 3 ** div * 2
		