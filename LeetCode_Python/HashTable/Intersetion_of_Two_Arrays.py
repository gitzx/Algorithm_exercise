'''
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:

    Each element in the result must be unique.
    The result can be in any order.
'''

class Solution(object):
	def intersetion(self, nums1, nums2):
		set1 = set(nums1)
		ans = []
		for x in nums2:
			if x in set1:
				ans += x,
				set1.remove(x)
		return ans

	def intersetion2(self, nums1, nums2):
		return list(set(nums1) & set(nums2))
		