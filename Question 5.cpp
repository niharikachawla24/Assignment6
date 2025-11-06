#include <iostream>
struct Node{
    int data;
    Node* next;
};

Node* head=NULL; 
Node* current= head;

 void create_node(int x,Node* &head,Node* &current){
     Node* NewNode=new Node; 
     NewNode->data=x;
     NewNode->next=NULL;
     
     if(head==NULL){
         head=NewNode;
    current=head; } else 
     {current->next=NewNode; 
        current=current->next;  }
      
      }

bool isCircular(Node* head){ Node* slow=head;
Node* fast=head;

if (head==NULL) 
        return false;
        
while(fast!=NULL&&fast->next!=NULL){ 
    
    slow=slow->next;
    fast=fast->next->next;
   
    
    if (slow==fast){ 
        return true; } 
} return false;
    }
    
int main() { create_node(3,head,current);
create_node(4,head,current);
create_node(5,head,current);
current->next=head;
std::cout<<isCircular(head);
}
