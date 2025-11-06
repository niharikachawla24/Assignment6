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

void display(Node* head){ Node* temp=head;


if (head==NULL) 
      {  std::cout<<"No nodes!\n";} 
      else
   {     

do {  std::cout<<temp->data<<"\t";
    temp=temp->next;
    } while(temp!=head);
   std::cout<<head->data<<"\n";
    }
   }

    
int main() { create_node(20, head, current);
    create_node(100, head, current);
    create_node(40, head, current);
    create_node(80, head, current);
    create_node(60, head, current);

current->next=head;
display(head);
}
