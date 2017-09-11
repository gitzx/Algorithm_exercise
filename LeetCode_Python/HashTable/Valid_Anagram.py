'''
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
'''

class Solution(object):
	def isAnagram(self, s, t):
		return sorted(s) == sorted(t)

	def isAnagram2(self, s, t):
		from collections import Counter
		return Counter(s).items() == Counter(t).items()
		