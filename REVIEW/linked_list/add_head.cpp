#include <iostream>
#include <fstream>
using namespace std;

ifstream ifs;

struct node
{
  int data;
  node *next;
};

node *createLinkList(int n){
// TODO
node *head = new node;
  ifs >> head->data;
  head->next = NULL;
  for (int i = 1; i < n; i++)
  {
    node *p = head;
    node *temp = new node;
    ifs >> temp->data;
    temp->next = NULL;
    while (p->next != NULL)
    {
      p = p->next;
    }
    p->next = temp;
  }
  return head;
}

node *insertNode(node *head, node *newNode, int position)
{
// TODO
if (position <= 0)
  {
  }
  else if (position == 1)
  {
    newNode->next = head;
    head = newNode;
  }
  else
  {
    int k = 1;
    node *p = head;
    while (k != position - 1 && p->next != NULL)
    {
      p = p->next;
      k++;
    }
    newNode->next = p->next;
    p->next = newNode;
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

    node *newNode = new node();
    ifs >> newNode->data;
    int position = 0;
    ifs >> position;
    head = insertNode(head, newNode, position);

    print(head);
  }
  else
  {
    cout << "Invalid n" << endl;
  }

  ifs.close();
  return 0;
}
