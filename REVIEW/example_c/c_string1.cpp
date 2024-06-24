#include<iostream>
#include<string.h>
#include<string>
#include<cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

void process(char str[], char outstr[]) {
    // TODO
    int length = sizeof(str)/sizeof(str[0]);
    cout<<length<< endl;
    // int i = 0; // outstr
    // int j = -1; // str
    // bool found = false;

    // //ignore head space
    // while(++j < length && str[j] == ' ');
    // //read string
    // while(j < length){
    //     if(str[j] != ' '){
    //         //handle space before . , ! ?
    //         if(str[j] == '.' || str[j] == ',' || str[j] == '?' || str[j] == '!' && i - 1 >= 0 && str[i-1] == ' '){
    //             str[i-1] = str[j++];
    //         }
    //         //assign to new string
    //         else{
    //             str[i++] = str[j++];
    //         }
    //         found = false;
    //     }
    //     else if(str[j++] == ' '){
    //         if(!found){
    //             str[i++] = ' ';
    //             found = true; 
    //         }
    //     }

    // }
    // if(i<=1){
    //     memmove(str+i, str+length,length);
    // }
    // else{
    //     memmove(str+i-1, str+length, length);
    // }
    // memcpy(outstr,str,length);
}



int main(){
    char str[] = "  abc  def  ghi  " ;
    char *outstr = new char[strlen(str) + 1];
    process(str, outstr);
    //cout << outstr;
    return 0;


}