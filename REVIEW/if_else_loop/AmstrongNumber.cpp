#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

bool ArmstrongNum(int n){
    // TODO
int R, result;
int sum=0;
int count=0;
int m=n;
while(m!=0){
    m=m/10;
    ++count;
}
result=n;
while(n>0){
    R=n%10;
    sum=sum+pow(R,count);
    n=n/10;
}
if(result==sum) return true;
else return false;
}

int main(int arg, char** argv){
    ifstream ifs;
	ifs.open(argv[1]);
	int N;
	try
	{
		ifs >> N;
        printf("%s\n", ArmstrongNum(N)?"true":"false");
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}