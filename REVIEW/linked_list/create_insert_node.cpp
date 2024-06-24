#include <iostream>
#include <fstream>
using namespace std;

ifstream ifs;

struct node
{
  int data;
  node *next;
};

node *createLinkList(int n)
{
// TODO
int i=0;
node*head=NULL;
node *temp=NULL;
node*p=NULL;
for(i=0;i<n;i++)
{
  temp=(node*)malloc(sizeof(node));
  temp->next=NULL;
  ifs>> temp->data;
  if(head==NULL)
  {
    head=temp;
  }
  else
  {
    p=head;
    while (p->next!=NULL)
    
      p=p->next;
      p->next=temp; 
    
    
  }
  
}
  return head;
}

void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->data << endl;
    head = head->next;
  }
}

int main(int narg, char **argv)
{
  ifs.open(argv[1]);

  int n = 0;
  ifs >> n;
  if (n > 0)
  {
    node *head = createLinkList(n);
    print(head);
  }
  else
  {
    cout << "Invalid n" << endl;
  }

  ifs.close();
  return 0;
}
