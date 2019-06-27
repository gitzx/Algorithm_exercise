// The count-and-say sequence is the sequence of integers with the first five terms as following:

// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.

// Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

// Note: Each term of the sequence of integers will be represented as a string.

// Example 1:

// Input: 1
// Output: "1"
// Example 2:

// Input: 4
// Output: "1211"

package algos0038

func countAndSay(n int) string {
	buf := []byte{'1'}
	for n > 1 {
		buf = say(buf)
		n--
	}
	return string(buf)
}

func say(buf []byte) []byte {
	res := make([]byte, 0, len(buf)*2)
	i, j := 0, 1
	for i < len(buf) {
		for j < len(buf) && buf[i] == buf[j] {
			j++
		}
		res = append(res, byte(j-i+'0'), buf[i])
		i = j
	}
	return res
}
