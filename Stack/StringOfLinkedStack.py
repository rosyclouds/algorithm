class Node:
	def __init__(self,data,node=None):
		self.data=data
		self.nextNode=node

class StringOfLinkedStack:
	def __init__(self,first=None):
		self.first=first

	def push(self,node):
		node.nextNode=self.first
		self.first=node

	def pop(self):
		if self.first is not None:
			result=self.first.data
			self.first=self.first.nextNode
			return result

	def empty(self):
		return self.first is None


if __name__ == '__main__':
	input_list=['a','b','-','-','c','-','k','-']
	s=StringOfLinkedStack()
	for c in input_list:
		if c=="-":
			print(s.pop(),end=' ')
		else:
			s.push(Node(c))
	print('\n',s.empty())