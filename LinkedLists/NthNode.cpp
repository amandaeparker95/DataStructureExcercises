#include <iostream>
using namespace std;

struct Node {  //defines the structure of what a node is in the linkedlist
int data;
Node* next;
};

Node* head = NULL; //pointer for the head node

Node* createLinkedList() {  //function used to create a linked list
  Node* temp;
  for(int i = 5; i >= 1; i--) { //this loop creates 5 nodes but this can be adjusted
    Node* node = new Node(); //will allocate space for the 5 nodes
    node->data = i; //assigns a value of 1-5 to each node
    node->next = NULL;
    if (head == NULL) {  //creates each node and points to next one
      head = node; 
      temp = node;
    }
  else {
    temp->next = node;
    temp = node;
  }
}
  return head;
  }

void displayList(Node* head) { //display the linked list
  struct Node* current = head;

  if(head == NULL) { //if linked list is empty
    cout << "Linked List is empty" << endl;
    return;
  }

  cout << "Linked list: \n";
  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
  }
}

int countNodes(Node* head){
  Node* temp = head; //temporary pointer
  int numNodes = 0; //Number of nodes

  while(temp != NULL){
    numNodes++; //will increase until nodes are counted
    temp = temp->next; //temp will move to each node until it reaches the end
  }
  return numNodes;
}

Node* removeNth(Node* head, int n){
  int numNodes = countNodes(head);
  int removePOS = numNodes - n + 1;

  if (numNodes == 1 && removePOS == 1)
    return NULL;

  Node* temp = head, *prev = NULL;
  numNodes = 0;

  while(temp != NULL){
    numNodes++;
    if (numNodes == removePOS){
      if (prev == NULL)
        head = temp->next;
      else
        prev->next = temp->next == NULL ? NULL: temp->next;
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
}

int main() {
  Node* head = createLinkedList();
  displayList(head);

  cout << endl;
  head = removeNth(head, 2);
  displayList(head);
  return 0;
}