// Implement a method to return the kth from last element in a linked list

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
  
  //This functions keeps a counter and increments it at every recursive stack return.
  int kthToLast(node *head, int k){
    if (head == NULL)
      return 0;
    int index = kthToLast(head->next, k) + 1;
    if (index==k){
      cout<<"\nThe element is "<<head->data;
    }
    return index;
  }
  
  // This function passes the value of i by reference. Hence the value remains constant across the recursive stack
  node* kthToLastReference(node* head, int k, int &i){
    if (head==NULL)
      return NULL;
    node *nd = kthToLastReference(head->next, k, i);
    i = i +1;
    if (k==i){
      cout<<"\nThe element is "<<head->data;
    }
    return nd;
  }
  
  // This function places 2 pointer k nodes apart. 
  int kthToLastRunner(int k){
    node *curr = new node;
    node *runner = new node;
    curr=head;
    runner=head;
    for(int i=0;i<k;i++){
      if(runner->next==NULL){
        cout<<"out of bounds";
        return 0;
      }
      runner=runner->next;
    }
    while(runner!=NULL){
      curr=curr->next;
      runner=runner->next;
    }
    cout<<"\nThe element is "<<curr->data;
    return 0;
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
  node *a = obj.gethead();
  obj.kthToLast(a, 2);
  int i =0;
  obj.kthToLastReference(a, 3, i);
  obj.kthToLastRunner(3);
  return 0;
}


