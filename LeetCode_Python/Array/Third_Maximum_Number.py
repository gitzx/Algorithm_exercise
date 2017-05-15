'''
Given a non-empty array of integers, return the third maximum number in this array. 
If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.

'''

class Solutiion(object):
	def thirdMax(self, nums):
		second = third = 0
		maximum = max(nums)
		for n in nums:
			if n != maximum and n > second:
				second = n
		for n in nums:
			if n != maximum and n != second and n > third:
				third = n
		if third != 0:
			return third
		else:
			return maximum

	def thirdMax2(self, nums):
		maximum = second = third = None 
		for n in nums:
			if n > maximum:
				maximum, second, third = n, maximum, second
			elif maximum > n > second:
				second, third = n, second
			elif second > n > third:
				third = n
		return third if third is not None else maximum

if __name__ == '__main__':
	nums = [2, 2, 3, 1]
	result = Solutiion().thirdMax(nums)
	print result # 1
