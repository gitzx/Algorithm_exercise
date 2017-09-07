'''
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.

Example:

Input: "cbbd"

Output: "bb"

'''

class Solution(object):
	def longestPalindrome(self, s):
		palindrome = ''
        for i in range(len(s)):
            len1 = len(self.getLongestPalindrome(s, i, i))
            if len1 > len(palindrome): 
            	palindrome = self.getLongestPalindrome(s, i, i)
            len2 = len(self.getLongestPalindrome(s, i, i + 1))
            if len2 > len(palindrome): 
            	palindrome = self.getLongestPalindrome(s, i, i + 1)
        return palindrome

	def getLongestPalindrome(self, s, l, r):
		while l >= 0 and r < len(s) and s[l] == s[r]:
			l -= 1
			r += 1
		return s[l+1 : r]

	#dp 
	'''
	状态转移方程：
	if s[i] == s[j]:   dp[i][j] = dp[i + 1][j - 1] + 2           
	else:    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j])   
	'''
