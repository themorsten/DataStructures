class DoublyLinkedListNode:
  def __init__(self,value):
    self.value = value
    self.next = None
    self.prev = None


class DoublyLinkedList:
  def __init__(self):
    self.head = None
    self.tail = None

  def append(self, value):
    newNode = DoublyLinkedListNode(value)

    if self.head: # список непустой
      self.tail.next = newNode
      newNode.prev = self.tail
      self.tail = newNode

    else: # список пустой
      self.head = newNode
      self.tail = newNode

  def prepend(self, value):
    newNode = DoublyLinkedListNode(value)

    if self.head: # список непустой
      self.head.prev = newNode
      newNode.next = self.head
      self.head = newNode
    else:
      self.head = newNode
      self.tail = newNode

  def print(self):
    currentNode = self.head
    while(currentNode):
      print(currentNode.value)
      currentNode = currentNode.next
