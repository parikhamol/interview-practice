// Implement a method to delete duplicate values from a linked list

#include <iostream>
using namespace std;

struct node {
  int data;
  node *next;
};

class list{
  private:
  node *head, *tail;
  int arr[32767];
  public:
  list(){
    head=NULL;
    tail=NULL;
    for(int i=0;i<32676;i++){
      arr[i]=0;
    }
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
  
  // This method uses an extra buffer (hash map) to find duplicates.
  void delete_dups(){
    node *curr = new node;
    node *prev = new node;
    curr=head;
    while(curr!=NULL){
      if(arr[curr->data] >= 1){
        prev->next=curr->next;
      } else{
        arr[curr->data]++;
      }
      prev=curr;
      curr=curr->next;
    }
  }
  
  //This method uses two pointer to remove all subsequent duplicates from the linked list.
  void delete_dups_no_buffer(){
    node *current = new node;
    node *runner = new node;
    current=head;
    while(current!=NULL){
      runner = current;
      while(runner->next!=NULL){
        if(runner->next->data==current->data){
          runner->next = runner->next->next;
        } else{
          runner=runner->next;
        }
      }
      current=current->next;
    }
  }
  
};
int main() {
  list obj;
  obj.createnode(25);
  obj.createnode(50);
  obj.createnode(90);
  obj.createnode(25);
  obj.createnode(60);
  obj.createnode(80);
  cout<<"\n--------------------------------------------------\n";
  cout<<"---------------Displaying All nodes---------------";
  cout<<"\n--------------------------------------------------\n";
  obj.display();
  obj.delete_dups();
  cout<<"\n--------------------------------------------------\n";
  cout<<"---------------Displaying Non Duplicate nodes---------";
  cout<<"\n--------------------------------------------------\n";
  obj.display();
  obj.createnode(25);
  obj.createnode(60);
  cout<<"\n--------------------------------------------------\n";
  cout<<"---------------Displaying All nodes---------------";
  cout<<"\n--------------------------------------------------\n";
  obj.display();
  obj.delete_dups_no_buffer();
  cout<<"\n--------------------------------------------------\n";
  cout<<"---------------Displaying Non Duplicate nodes---------";
  cout<<"\n--------------------------------------------------\n";
  obj.display();
  return 0;
}


