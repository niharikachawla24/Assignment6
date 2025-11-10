#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;
Node* current = head;

void create_node(int x, Node*& head, Node*& current) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        current = head;
    } else {
        current->next = newNode;
        current = current->next;
    }
}

bool isCircular(Node* head) {
    Node* slow = head;
    Node* fast = head;

    if (head == NULL)
        return false;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main() {
    create_node(3, head, current);
    create_node(4, head, current);
    create_node(5, head, current);
    current->next = head;
    cout << isCircular(head);
    return 0;
}
