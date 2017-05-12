'''
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
find the duplicate one.

Note:
    You must not modify the array (assume the array is read only).
    You must use only constant, O(1) extra space.
    Your runtime complexity should be less than O(n2).
    There is only one duplicate number in the array, but it could be repeated more than once.
'''

class Solution(object):
    def findTheDuplicateNumber(self, nums):
        left, right = 1, len(nums)-1
        while left <= right:
            mid = (left+right)>>1
            count = sum([1 for num in nums if num <= mid])
            if count <= mid:
                left = mid + 1
            else:
                right = mid -1
        return left

    def findTheDuplicateNumber2(self, nums):
        slow, fast = 0, nums[nums[0]]
        while slow != fast:
            slow = nums[slow]
            fast = nums[nums[fast]]

        slow = 0
        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]
        return slow


if __name__ == '__main__':
    nums = [1,2,3,3,4,5]
    result = Solution().findTheDuplicateNumber2(nums)
    print result
