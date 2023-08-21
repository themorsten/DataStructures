class LinkedListNode:
  def __init__ (self,value):
    self.value = value
    self.next = None

class LinkedList:
  def __init__(self):
    self.head = None
    self.tail = None

  def append(self,value):
    newNode = LinkedListNode(value) # создаем звено

    if self.head: # список непустой 
      self.tail.next = newNode
      self.tail = newNode

    else: # список пустой
      self.head = newNode
      self.tail = newNode

  def prepend(self, value):
    newNode = LinkedListNode(value)

    if self.head: # список непустой
      newNode.next = self.head
      self.head = newNode

    else: # список пустой
      self.head = newNode
      self.tail = newNode
