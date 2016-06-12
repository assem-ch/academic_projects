/*
  Insert Node at the end of a linked list
  head pointer input could be NULL as well for empty list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{ Node *p,*k;
  for(p=head; p!=NULL && p->next != NULL; p=p->next){  };
    Node *q; q = new Node;
    q->data = data;
    q->next = NULL;
    if(p) p->next =q;
    else head = q;


 return head;
}
