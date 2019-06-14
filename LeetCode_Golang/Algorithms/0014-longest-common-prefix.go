// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
// Note:

// All given inputs are in lowercase letters a-z.

package algos0014

func longestCommonPrefix(strs []string) string {
	short := shotest(strs)
	for i, r := range short {
		for j := 0; j < len(strs); j++ {
			if strs[j][i] != byte(r) {
				return strs[j][:i]
			}
		}
	}
	return short
}

func shotest(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	res := strs[0]
	for _, s := range strs {
		if len(res) > len(s) {
			res = s
		}
	}
	return res
}
