class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

def createLinklist(n,nums):
    head = ptr = Node(nums[0])
    for i in range(1,n):
        new = Node(nums[i])
        ptr.next = new
        ptr = ptr.next
    return head

def traversal(head):
    while(head!=None):
        print(f"Element :: {head.data}")
        head = head.next

def deleteFirstNode(head):
    return head.next


n = 5
nums = [89,43,12,65,38]
head = createLinklist(n,nums)
traversal(head)

head = deleteFirstNode(head)
print("After delete first node\n")
traversal(head)

