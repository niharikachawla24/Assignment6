#include <iostream>
struct Node{
    int data;
    Node* prev;
    Node* next;
    };  
Node* head=nullptr;
Node* tail=nullptr;
Node* current=nullptr;

void createNode(int x){
    
    Node* newNode= new Node;
    newNode->data=x;
    newNode->next=nullptr;
    newNode->prev=nullptr;
    
    if(head==nullptr){
        head=tail=newNode;
    }
     else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}


  bool isPalindrome(Node* temp,Node* temp2){ 
      while (temp!=temp2 && temp2->next!=temp){
         if(temp->data!=temp2->data) 
         {
             return false;
           } 
      temp=temp->next;
          temp2=temp2->prev;
      } return true;
  }
  

int main() {
  createNode(1);
  createNode(2);
  createNode(3);
  createNode(3);
  createNode(2);
  createNode(1);
 
 int x=isPalindrome(head,tail);
  if(x==1){std::cout<<"True\n";};
 if(x==0){std::cout<<"False\n";};

}
