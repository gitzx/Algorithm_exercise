'''
A linked list is given such that each node contains an additional random pointer 
which could point to any node in the list or null.

Return a deep copy of the list.

'''

'''
class RandomListNode(object):
	def __init__(self, x):
	    self.label = x
        self.next = None
        self.random = None
        
'''

class Solution(object):
	def copyRandomList(self, head):
		if head == None:
			return None
		tmp = head
		while tmp:
			newNode = RandomListNode(tmp.label)
			newNode.next = tmp.next
			tmp.next = newNode
			tmp = tmp.next.next
		tmp = head
		while tmp:
			if tmp.random:
				tmp.next.random = tmp.random.next
			tmp = tmp.next.next
		newhead = head.next
		pold = head
		pnew = newhead
		while pnew.next:
			pold.next = pnew.next
			pold = pold.next
			pnew.next = pold.next
			pnew = pnew.next
		pold.next = None
		pnew.next = None
		return newhead

	def copyRandomList2(self, head):
		nodeDict = dict()
		dummy = RandomListNode(0)
		pointer, newhead = head, dummy
		while pointer:
			newNode = RandomListNode(pointer.label)
			newhead.next = newNode
			nodeDict[pointer] = newhead.next
			newhead = newhead.next
			pointer = pointer.next
		pointer, newhead = head, dummy.next
		while pointer:
			if pointer.random:
				newhead.random = nodeDict[pointer.random]
			pointer, newhead = pointer.next, newhead.next
		return dummy.next



