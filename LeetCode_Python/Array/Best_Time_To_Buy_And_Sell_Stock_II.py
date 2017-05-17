'''
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

'''

class Solution(object):
	def maxProfit(self, prices):
		maximum = 0
		for i in range(0, len(prices)-1):
			if prices[i+1] >= prices[i]:
				maximum += prices[i+1] - prices[i]
		return maximum


if __name__ == '__main__':
	prices = [7, 1, 5, 3, 6, 4]
	result = Solution().maxProfit(prices)
	print result  # 7