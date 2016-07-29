class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        
    
class LinkedQueue:
    def __init__(self):
        self.head=None
        self.tail=None

    def is_empty(self):
        return self.head is None

    def size(self):
        temp=self.head
        i=0
        while(temp!=None):
            temp=temp.next
            i+=1
        return i

    def enqueue(self,data):
        oldtail=self.tail
        self.tail=Node(data)
        if self.is_empty():
            self.head=self.tail
        else:
            oldtail.next=self.tail

    def dequeue(self):
        if self.is_empty():
            return
        else:
            temp=self.head.data
            self.head=self.head.next
            if self.is_empty():
                self.tail=None
            return temp

if __name__=="__main__":
    q=LinkedQueue()
    lists=["this","is","a","-","-","test","-","-"]
    for item in lists:
        if item=="-":
            print(q.dequeue())
        else:
            q.enqueue(item)

        
    
    
    
