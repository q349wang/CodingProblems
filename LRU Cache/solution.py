from typing import List
# Write any import statements here

class Node:
  def __init__(self, value: int):
    self.value = value
    self.next = None
    self.prev = None
  
class LRUCache:
  def __init__(self, capacity):
    self.head = None
    self.tail = None
    
    self.map = {}
    self.capacity = capacity
    self.size = 0
    
  def add(self, value):
    if value in self.map:
      if self.size == 1:
        return
      
      curr_node = self.map[value]
      
      if curr_node.next is not None:
        curr_node.next.prev = curr_node.prev
      
      if curr_node.prev is not None:
        curr_node.prev.next = curr_node.next
        
      if self.head is not None:
        self.head.prev = curr_node
        
      if curr_node is self.tail and self.tail is not self.head:
        self.tail = self.tail.prev
      
      curr_node.next = self.head
      curr_node.prev = None
      self.head = curr_node
      
    else:
      new_node = Node(value)
       
      if self.size == self.capacity:
        
        del self.map[self.tail.value]
        
        if self.head is self.tail:
          self.head = None
          
        if self.tail.prev:
          self.tail.prev.next = None
        
        self.tail = self.tail.prev
        
        self.size -= 1
        
      if self.head is not None:
        self.head.prev = new_node
          
      new_node.next = self.head
      self.head = new_node
      
      self.map[value] = new_node
      
      if self.tail is None:
        self.tail = new_node
        
      self.size += 1
        
      
  def check(self, value):
    if value in self.map:
      return True
    return False

def getMaximumEatenDishCount(N: int, D: List[int], K: int) -> int:
  # Write your code here
  
  dishes = 0
  
  cache = LRUCache(K)
  
  for i in range(0, N):
    if not cache.check(D[i]):
      dishes += 1
      
      cache.add(D[i])
  
  return dishes
