# -*- coding: utf-8 -*-

'''
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
The number of elements initialized in nums1 and nums2 are m and n respectively.

'''

class Solution(object):
	def merge(self, nums1, m, nums2, n):
		i = m-1
		j = n -1
		idx = m + n -1
		while i >= 0 and j >= 0:
			if nums1[i] > nums2[j]:
				nums1[idx] = nums1[i]
				idx -= 1
				i -= 1
			else:
				nums1[idx] = nums2[j]
				idx -= 1
				j -= 1
		while i >= 0:
			nums1[idx] = nums1[i]
			idx -= 1
			i -= 1
		while j >= 0:
			nums1[idx] = nums2[j]
			idx -= 1
			j -= 1

	def merge2(self, nums1, m, nums2, n):
		for i in range(n):
			nums1[i+m] = nums2[i]
		nums1.sort()

if __name__ == '__main__':
	nums1 = [1,3,5,7,9] + [0 for i in range(5)]
	nums2 = [2,4,6,8,10]
	Solution().merge(nums1, 5, nums2, 5)
	print nums1  # [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
