/*
  Insert Node at a given position in a linked list
  The linked list will not be empty and position will always be valid
  First element in the linked list is at position 0
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{ Node *p=head;
  Node *q = new Node;
  q->data = data;
  if(position==0){
     q->next = head;
     head = q;
  }
  else{
    for(int i = 0; i <position-1 && p!=NULL; i++, p=p->next){}
    q->next = p->next;
    p->next = q;

  }

  return head;
}
