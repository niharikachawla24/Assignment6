#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void display_reverse() {
    if (head == NULL) return;
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

void correct_pointer() {
    if (head == NULL) return;
    Node* temp = head;
    while (temp->next != NULL) {
        if (temp->next->prev != temp)
            temp->next->prev = temp;
        temp = temp->next;
    }
}

int main() {
    head = new Node{1, NULL, NULL};
    head->next = new Node{2, NULL, head};
    head->next->next = new Node{3, NULL, head}; 
    head->next->next->next = new Node{4, NULL, head->next->next};
    head->next->next->next->prev = head->next->next;

    cout << "Incorrect List:\n";
    display();
    display_reverse();

    correct_pointer();

    cout << "\nCorrected List:\n";
    display();
    display_reverse();
}
