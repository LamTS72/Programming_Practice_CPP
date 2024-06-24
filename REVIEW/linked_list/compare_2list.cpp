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
node *L_list=NULL;
int *value=new int[n];
for (int i=0;i<n;i++){
    ifs >> value[i];
}

for (int i=0;i<n;i++){
    node *newE,*p;
    newE = new node;
    newE->data=value[i];
    newE->next=NULL;
    if (L_list == NULL){
        L_list=newE;
    }
    else {
        p  = L_list;
        while(p->next != NULL){
            p = (p->next);
        }
        p->next = newE;

    }
}
return L_list;
}

bool isEqual(node *head1, node *head2)
{
// TODO
int length1 = 0;
    int length2 = 0;
    for(node *p = head1; p != NULL; p = p->next){
        length1++;
    }
    for(node *p = head2; p != NULL; p = p->next){
        length2++;
    }
    if (length1 != length2) return 0;
    else {
        for (int i=0;i<length1;i++){
            if (head1->data != head2->data)
                return 0;
            else {
                head1=head1->next;
                head2=head2->next;
            }
        }
    }
    return 1;
}

int main(int narg, char **argv)
{
  ifs.open(argv[1]);

  int n = 0;
  ifs >> n;
  if (n <= 0)
  {
    cout << "Invalid n" << endl;
    return 0;
  }
  node *head1 = createLinkList(n);

  int m = 0;
  ifs >> m;
  if (m <= 0)
  {
    cout << "Invalid m" << endl;
    return 0;
  }
  node *head2 = createLinkList(m);

  cout << isEqual(head1, head2) << endl;

  ifs.close();
  return 0;
}
