class ListNode:
    
    def __init__(self, val=0, next=None):
        """
        Initialize Node
        """
        self.val = val
        self.next = next
    
    def reverseList(self, head):
        """
        Reverse the linked list starting at head
        """
        pre=None
        curr=head
        while curr!=None:
            nxt=curr.next
            curr.next=pre
            pre=curr
            curr=nxt
            head=curr
        return pre
