/*
  Delete Node at a given position in a linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
  if (position == 0){
      Node *p = head;
      head = head -> next;
      delete p;
  }
    else{
        Node *p=head,*q;
        for(int i=0; i<position-1; i++,p=p->next);
        q = p->next;
        p->next = p->next->next;
        delete q;
    }

    return head;
}
