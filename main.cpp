#include <iostream>

using namespace std;


struct Node {
    int data;
    Node* link;
};

void traverseLink(Node* head);
void insertBeginning(Node*& head, int newData);
void insertEnd(Node** head, int newData);
void insertAfter(Node* prevNode, int newData);

int main() {
   Node* head = NULL;
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();

    first -> data = 1;
    first -> link = second;

    second -> data = 2;
    second -> link = third;

    third -> data = 3;
    third -> link = NULL;

    head = first;

    cout << "Original linked list:" << endl;
    traverseLink(head);
    insertBeginning(head,0);
    cout << "After inserting at the beginning:" << endl;
    traverseLink(head);

    insertEnd(&head, 4);
    cout << "After inserting at the end:" << endl;
    traverseLink(head);

    insertAfter(second, 5);
    cout << "After inserting after second node:" << endl;
    traverseLink(head);


}
void traverseLink(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        cout << current -> data << " -> ";
        current = current -> link;
    }
    cout << "NULL" << endl;

}

void insertBeginning(Node*& head, int newData)
{
    Node* newNode = new Node();
    newNode -> data = newData;
    newNode -> link = head;
    head = newNode;
}

void insertEnd(Node** head, int newData){
    Node* newNode = new Node();

    newNode -> data = newData;
    newNode -> link = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* last = *head;

    while (last -> link != NULL)
        last = last -> link;

    last -> link = newNode;
}

void insertAfter(Node* prevNode, int newData){
    if (prevNode == NULL) {
        cout << "The given previous node cannot be NULL." << endl;
        return;
    }

    Node* newNode = new Node();
    newNode -> data = newData;
    newNode -> link = prevNode -> link;
    prevNode -> link = newNode;
}