'''
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
'''

'''
若字母出现偶数次，则直接累加至最终结果

若字母出现奇数次，则将其值-1之后累加至最终结果

若存在出现奇数次的字母，将最终结果+1
'''

class Solution(object):
	def longestPalindrome(self, s):
		ans = odd = 0
		cnt = collections.Counter(s)
		for c in cnt:
			ans += cnt[c]
			if cnt[c] % 2 == 1:
				ans -= 1
				odd += 1
		return ans + (odd > 0)
