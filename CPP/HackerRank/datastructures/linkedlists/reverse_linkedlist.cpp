/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
    Node *p = head,*q=NULL,  *prev = NULL;
    while(p){
        q = p->next;
        p->next = prev;
        prev = p;
        p = q;

    }
    return prev;


}
