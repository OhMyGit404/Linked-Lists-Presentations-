#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to traverse and print the linked list
void traverseList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}


int main() {
    // Create three nodes
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // Initialize the nodes
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // Traverse and print the list
    traverseList(head);

    // Free allocated memory
    delete head;
    delete second;
    delete third;

    return 0;
}