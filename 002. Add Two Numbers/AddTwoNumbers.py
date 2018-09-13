# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        val1 = self.getSum(l1)
        val2 = self.getSum(l2)      
        val3 = val1 + val2
        print (str(val1) + " + " + str(val2) + " = " + str(val3))
        strVal3 = str(val3)
        curNode = ListNode(strVal3[0])
        for i in range(1, len(strVal3)):
            newNode = ListNode(strVal3[i])
            newNode.next = curNode
            curNode = newNode
        return curNode
    
    def genListNode(self, l):
        curNode = ListNode(l[0])
        for i in range(1, len(l)):
            newNode = ListNode(l[i])
            newNode.next = curNode
            curNode = newNode
        return curNode
    
    def printListNode(self, l):
        cur = l
        print(cur.val)
        while cur.next != None:
            cur = cur.next
            print(cur.val)
    
    def getSum(self, node):
        curNode = node
        sum = curNode.val
        power = 10
        while curNode.next != None:
            sum += curNode.next.val * power
            curNode = curNode.next           
            power *= 10
        return sum

list1 = [2, 4, 3]
list2 = [5, 6, 4]

solution = Solution()
listNode1 = solution.genListNode(list1)
listNode2 = solution.genListNode(list2)
listNode3 = solution.addTwoNumbers(listNode1, listNode2)

solution.printListNode(listNode3)

