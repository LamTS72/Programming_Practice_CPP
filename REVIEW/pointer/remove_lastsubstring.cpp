#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

#define MAX_LEN 200

void removeLastSubString(char *str, char *sub)
{
// TODO
int a = strlen(str);
    int b = strlen(sub);
    char *strchange = new char [a+1];
    char *subchange = new char [b+1];
    strchange[a]='\0';
    subchange[b]='\0';
    for (int i=0;i< a;i++)
    {
        *(strchange+i)= *(str+a-1-i);
    }
    for (int i=0;i< b;i++)
    {
        *(subchange+i)= *(sub+b-1-i);
    }
    char *findstr=strstr(strchange,subchange);
    if (findstr!=NULL)
        memmove(str+strlen(findstr)-b,str+strlen(findstr),200);
}

int main(int narg, char **argv)
{
  ifstream ifs;
  ifs.open(argv[1]);

  char str1[MAX_LEN];
  char str2[MAX_LEN];

  ifs.get(str1, MAX_LEN, '\n');
  ifs.ignore(MAX_LEN, '\n');
  ifs.get(str2, MAX_LEN, '\n');
  ifs.ignore(MAX_LEN, '\n');

  removeLastSubString(str1, str2);
  cout << str1 << endl;
  ifs.close();
  return 0;
}