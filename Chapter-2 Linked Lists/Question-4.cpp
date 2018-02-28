// Implement a method to partition a  linked list so that all nodes with value less the partition are before it.

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
  
  void display(node* head){
     node *temp = new node;
    temp=head;
    while(temp!=NULL) {
      cout<<temp->data<<"->";
      temp=temp->next;
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
  
  // This function creates a new list where it add nodes with values less thn the partition to the head and nodes with value greater than partition to the tail.
  void partition(list *newlist, int val){
    node *temp = new node;
    temp = head;
    newlist->head=temp;
    newlist->tail=temp;
    while(temp!=NULL){
      node* next = temp->next;
      if(temp->data < val){
        temp->next=newlist->head;
        newlist->head=temp;
      }else{
        newlist->tail->next=temp;
        newlist->tail=temp;
      }
      temp=next;
    }
    newlist->tail->next=NULL;
    cout<<"\n--------------------------------------------------\n";
    cout<<"---------------Displaying Partitioned nodes-----------";
    cout<<"\n--------------------------------------------------\n";
    display(newlist->head);
    return;
  }
  
};
int main() {
  list obj;
  obj.createnode(25);
  obj.createnode(50);
  obj.createnode(90);
  obj.createnode(60);
  obj.createnode(50);
  obj.createnode(40);
  obj.createnode(800);
  cout<<"\n--------------------------------------------------\n";
  cout<<"---------------Displaying All nodes---------------";
  cout<<"\n--------------------------------------------------\n";
  obj.display();
  list newlist;
  obj.partition(&newlist,50);
  return 0;
}

