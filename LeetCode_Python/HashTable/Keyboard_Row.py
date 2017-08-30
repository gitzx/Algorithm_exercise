'''
Given a List of words, return the words that can be typed using letters 
of alphabet on only one row's of American keyboard like the image below.

American keyboard

Example 1:

Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]

Note:

    1.You may use one character in the keyboard more than once.
    2.You may assume the input string will only contain letters of alphabet.
'''

class Solution(object):
	def findWords(self, words):
		rs = map(set, ['qwertyuiop','asdfghjkl','zxcvbnm'])
		ans = []
		for word in words:
			wset = set(word.lower())
			if any(wset <= rset for rset in rs):
				ans.append(word)
		return ans