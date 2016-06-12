int len(Node *head){
    int cpt =0;
    for(Node *p=head;p;p=p->next) cpt++;
    return cpt;
}
/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    Node *p, *q;
    p = headA;
    q = headB;
    int la = len(headA), lb= len(headB);
    while (la > lb) { la--; p=p->next;
    }
    while (lb > la) { lb--; q=q->next;
    }
    for(int i = la; i>0; i--){
        if(p==q){
            return p->data;
        }
        p=p->next;
        q=q->next;
    }
    return 0;
}
