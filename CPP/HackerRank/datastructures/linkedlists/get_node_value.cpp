int len(Node *head){
    int cpt =0;
    for(Node *p=head; p!=NULL; p=p->next) { cpt ++ ;};
    return cpt;
}
/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{ int l = len(head);
   Node *p = head;
  for(int i = 0; i < l - positionFromTail-1; i++){p=p->next;};
   return p->data;
}
