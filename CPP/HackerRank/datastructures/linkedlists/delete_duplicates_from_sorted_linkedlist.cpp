/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
  for(Node *p = head; p; p=p->next){
      while (p->next && p->data==p->next->data){
          Node *q=p->next;
          p->next=p->next->next;
          delete q;
      }
  }
    return head;
}
