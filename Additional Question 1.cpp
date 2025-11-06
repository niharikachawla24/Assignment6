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

Node* splitCircular(Node* &head){ Node* slow=head;
Node* fast=head;

if (head==NULL||head->next==head)
    return NULL;

        
 while (fast->next!=head&&fast->next->next!=head){ 
    slow=slow->next;
    fast=fast->next->next;
}

 if (fast->next->next==head)
        fast=fast->next;
        
Node* head2=slow->next;
   fast->next=head2;
   slow->next=head;
return head2;} 

void display(Node* head){ Node* temp=head;

std::cout<<"List is\n";
if (head==NULL) 
      {  std::cout<<"No nodes!\n";} 
      else
   {     

do {  std::cout<<temp->data<<"\t";
    temp=temp->next;
    } while(temp!=head);
   std::cout<<"\n";
    }
   }

    
int main() { create_node(3,head,current);
create_node(4,head,current);
create_node(5,head,current);
current->next=head;
Node* head2=splitCircular(head);
display(head);
display(head2);

}
