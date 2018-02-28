// Implement a method to delete an node given access to just that node

#include <iostream>
using namespace std;

struct node {
  int data;
  node *next;
};

class list{
  private:
  node *head, *tail;
  public:
  list(){
    head=NULL;
    tail=NULL;
  }
  
  node* gethead(){
    return head;
  }
  void createnode(int value){
    node *temp = new node;
    temp->data=value;
    temp->next=NULL;
    if (head==NULL){
      head=temp;
      tail=temp;
      temp=NULL;
    } else{
      tail->next=temp;
      tail=temp;
    }
  }
  
  void display(){
    node *temp = new node;
    temp=head;
    while(temp!=NULL) {
      cout<<temp->data<<"->";
      temp=temp->next;
    }
  }
  
  void delete_node(node *element){
    if (element == NULL || element->next==NULL){
      cout<<"Cannot delete since its the tail";
      return;
    }
    element->data=element->next->data;
    element->next=element->next->next;
    return;
  }
  
};
int main() {
  list obj;
  obj.createnode(25);
  obj.createnode(50);
  obj.createnode(90);
  obj.createnode(60);
  obj.createnode(80);
  cout<<"\n--------------------------------------------------\n";
  cout<<"---------------Displaying All nodes---------------";
  cout<<"\n--------------------------------------------------\n";
  obj.display();
  node *head = obj.gethead();
  obj.delete_node(head->next);
  cout<<"\n--------------------------------------------------\n";
  cout<<"---------------Displaying After Deletion--------------";
  cout<<"\n--------------------------------------------------\n";
  obj.display();
  return 0;
}


