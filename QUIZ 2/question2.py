class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def findCycleStart(head):
    # If the list is empty or has only one node, there is no cycle
    if not head or not head.next:
        return None

    # Use Floyd's cycle-finding algorithm
    slow = head
    fast = head

    # Move slow pointer one step and fast pointer two steps
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

        # If slow and fast pointers meet, there is a cycle
        if slow == fast:
            break

    # If there is no cycle, return None
    if not fast or not fast.next:
        return None

    # Reset slow pointer to the head
    slow = head

    # Move both pointers one step at a time until they meet
    while slow != fast:
        slow = slow.next
        fast = fast.next

    # Return the node where they meet
    return slow