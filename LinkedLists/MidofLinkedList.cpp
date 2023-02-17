#include <iostream>
using namespace std;

struct Node {
int data;
Node* next;
};

class NodeOperation {
public:
  void pushNode (struct Node** head_ref, int data_val) //add new node
  {
    struct Node* new_node = new Node(); //allocate memory for node
    new_node->data = data_val; //node data
    new_node->next = *head_ref; //link the old list of the new node
    *head_ref = new_node; //move the head to point to the new node
  }

 void printNode(struct Node* head) //print the linked list
{
  while (head != NULL) {
    cout << head->data << "->";
    head = head->next;
  }
  cout << "NULL" << endl;
}


void printMiddle(struct Node* head) {
  struct Node *slow_ptr = head;
  struct Node *fast_ptr = head;
  
  if (head!= NULL) {
     while (fast_ptr != NULL && fast_ptr->next != NULL) {
       fast_ptr = fast_ptr->next->next;
       slow_ptr = slow_ptr->next;
     }

    cout << "The middle element is [" << slow_ptr->data << "]"<< endl;
  }
}
};

int main() {
  class Node* head = NULL;
  class NodeOperation* temp = new NodeOperation();
  for (int i = 5; i > 0; i--) {
    temp->pushNode(&head, i);
    temp->printNode(head);
    temp->printMiddle(head);
    
  }
  return 0;
}