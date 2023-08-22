class LinkedListNode: # звено
  def __init__ (self,value):
    self.value = value
    self.next = None

class LinkedList: # связный список
  def __init__(self):
    self.head = None
    self.tail = None

  def append(self,value): # добавить в конец 
    newNode = LinkedListNode(value)

    if self.head: # список непустой 
      self.tail.next = newNode
      self.tail = newNode

    else: # список пустой
      self.head = newNode
      self.tail = newNode

  def prepend(self, value): # добавить в начало 
    newNode = LinkedListNode(value)

    if self.head: # список непустой
      newNode.next = self.head
      self.head = newNode

    else: # список пустой
      self.head = newNode
      self.tail = newNode

  def find(self,value): # поиск звена по значению val, возвращает указатель на звено или None
    curNode = self.head
    while(curNode):
      if curNode.value == value:
        return curNode
      curNode = curNode.next
    return None

      
  def print(self):
    currentNode = self.head
    while(currentNode):
      print(currentNode.value)
      currentNode = currentNode.next
