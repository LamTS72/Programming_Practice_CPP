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
int m;
  node *head=NULL;
  node *ptr=new node();
  ifs>>ptr->data;
  ptr->next=NULL;
  head=ptr;
  for(int i=1;i<n;i++)
  {
    ifs>>m;
    node *ptr=new node();
    ptr->data=m;
    ptr->next=head;
    head=ptr;
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
