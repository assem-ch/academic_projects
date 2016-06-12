/*
  Merge two sorted lists A and B as one linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{ Node *head = NULL, *p=headA,*q=headB,*r=NULL;
  if (!headA) return headB;
  if (!headB) return headA;
  while(p && q){
      if (p->data<=q->data){
          if(r) r->next = p;
          else { head=p;
          }
          r = p;
          p = p->next;
      }
      else {
          if(r) r->next = q;
          else { head=q;
          }
          r = q;
          q = q->next;
      }

   if(q){if (r) r->next=q;else head=q;}
       if(p) {if (r) r->next=p;else head=p;}
  }
 return head;
}