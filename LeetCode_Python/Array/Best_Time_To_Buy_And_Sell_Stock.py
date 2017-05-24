
# -*- coding:utf-8 -*-
'''
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)

Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.

'''

import sys
class Solution(object):
	# dp, "局部最优和全局最优解法"
	def maxProfit(self, prices):
		if prices == None or len(prices) == 0:
			return 0
		tempMax = 0
		maximum = 0
		for i in range(0, len(prices) - 1):
			tempMax = max(tempMax + prices[i+1] - prices[i], 0)
			maximum = max(tempMax, maximum)
		return maximum

	def maxProfit2(self, prices):
		maximum = 0
		low = sys.maxint
		hight = 0
		for p in prices:
			if p - low > maximum:
				maximum = p - low
			if p < low:
				low = p
		return maximum


if __name__ == '__main__':
	prices = [7, 1, 5, 3, 6, 4]
	result = Solution().maxProfit(prices)
	print result   # 5

