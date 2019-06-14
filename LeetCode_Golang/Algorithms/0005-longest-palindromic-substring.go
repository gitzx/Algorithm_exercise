// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

// Example:

// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.

// Example:

// Input: "cbbd"
// Output: "bb"

package algos

func longestPalindrome(s string) string {
	if len(s) < 2 {
		return s
	}

	begin, maxLen := 0, 1
	for i := 0; i < len(s); {
		if len(s)-i <= maxLen/2 {
			break
		}
		b, e := i, i
		for e < len(s)-1 && s[e+1] == s[e] {
			e++
		}
		i = e + 1
		for b > 0 && e < len(s)-1 && s[b-1] == s[e+1] {
			b--
			e++
		}
		newLen := e + 1 - b
		if newLen > maxLen {
			maxLen = newLen
			begin = b
		}
	}
	return s[begin : begin+maxLen]
}
