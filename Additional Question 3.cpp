#include <iostream>
struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL; 
Node* tail = head;

void create_node(int x, Node* &head, Node* &tail){
    Node* NewNode = new Node;
    NewNode->data = x;
    NewNode->next = NULL;
    NewNode->prev = NULL;

    if(head == NULL){
        head = NewNode;
        tail = head;
    } else {
        tail->next = NewNode;
        NewNode->prev = tail;
        tail = tail->next;
    }
}

void display(Node* head){
    Node* temp = head;
    if(head == NULL){
        std::cout << "No nodes!\n";
        return;
    }
    while(temp != NULL){
        std::cout << temp->data << "\t";
        temp = temp->next;
    }
    std::cout << "\n";
}


Node* reverseK(Node* head, int k){
    Node* current = head;
    Node* newHead = NULL;
    Node* prevTail = NULL;

    while(current){
        Node* prev = NULL;
        Node* next = NULL;
        Node* tail = current;
        int count = 0;

        while(current && count < k){
            next = current->next;
            current->next = prev;
            current->prev = next;
            prev = current;
            current = next;
            count++;
        }

        if(!newHead) newHead = prev;
        if(prevTail){ prevTail->next = prev; prev->prev = prevTail; }
        prevTail = tail;
    }
    return newHead;
}


int main(){
    create_node(1, head, tail);
    create_node(2, head, tail);
    create_node(3, head, tail);
    create_node(4, head, tail);
    create_node(5, head, tail);

    std::cout << "Original list:\t";
    display(head); int k;   std::cout << "enter k:\t";
std::cin>>k;
  
    head = reverseK(head, k);

    std::cout << "Reversed every " << k << " nodes:\t";
    display(head);
}
