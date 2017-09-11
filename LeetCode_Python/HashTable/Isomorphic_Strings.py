'''
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
'''

class Solution(object):
	def isIsomorphic(self, s, t):
		srcMap, tgtMap = dict(), dict()
		for x in range(len(s)):
			src, tgt = srcMap.get(t[x]), tgtMap.get(s[x])
			if src is None and tgt is None:
				srcMap[t[x]], tgtMap[s[x]] = s[x], t[x]
			elif tgt != t[x] or src != s[x]:
				return False
		return True