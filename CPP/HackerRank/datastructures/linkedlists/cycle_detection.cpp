/*
  Detect loop in a linked list
  List could be empty also
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int HasCycle(Node* head)
{
   Node *slowNode, *fastNode;
    slowNode = head;
    fastNode = head;
  while (fastNode && fastNode->next) {
    if (fastNode->next == slowNode || fastNode->next->next == slowNode) {
        return 1;
    }
    fastNode = fastNode->next->next;
    slowNode = slowNode->next;
}
         return 0;
}