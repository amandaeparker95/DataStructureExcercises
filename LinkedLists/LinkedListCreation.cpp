#include <iostream>
using namespace std;

int num1, num2, num3;

struct Node {
    int data;
    Node* next;
};

int main() {

    cout <<"Enter 3 numbers for linked list: "<< endl;
    cin >> num1 >> num2 >> num3;
    
    
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    //allocate 3 nodes for the linked list
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = num1;
    head->next = second;

    second->data = num2;
    second->next = third;

    third->data = num3;
    third->next = NULL;

    cout <<"The linked list is: ";
    while (head != NULL) {
        cout << head->data <<" ";
        head = head->next;
    }

    return 0;
}