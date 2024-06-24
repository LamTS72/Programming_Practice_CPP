#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void printOrder(char *str1, char *str2, char *str3)
{
    if (strcmp(str1, str2) < 0){
        if (strcmp(str1, str3) < 0){
            if (strcmp(str2, str3) < 0){
                cout << str1 << "\n";
                cout << str2 << "\n";
                cout << str3 << "\n";
            }
            else{
                cout << str1 << "\n";
                cout << str3 << "\n";
                cout << str2 << "\n";
            }
        }
        else{
            cout << str3 << "\n";
            cout << str1 << "\n";
            cout << str2 << "\n";
        }
    }
    else{
        if (strcmp(str2, str3) < 0){
            if (strcmp(str1, str3) < 0){
                cout << str2 << "\n";
                cout << str1 << "\n";
                cout << str3 << "\n";
            }
            else{
                cout << str2 << "\n";
                cout << str3 << "\n";
                cout << str1 << "\n";
            }
        }
        else{
            cout << str3 << "\n";
            cout << str2 << "\n";
            cout << str1 << "\n";
        }
    }
}

int main(int narg, char **argv)
{
  ifstream ifs;
  ifs.open(argv[1]);

  char str1[100];
  char str2[100];
  char str3[100];

  ifs.get(str1, 100, '\n');
  ifs.ignore(100, '\n');
  ifs.get(str2, 100, '\n');
  ifs.ignore(100, '\n');
  ifs.get(str3, 100, '\n');
  ifs.ignore(100, '\n');

  printOrder(str1, str2, str3);

  ifs.close();
  return 0;
}
