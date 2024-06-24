#include <iostream>
#include <fstream>
using namespace std;

void print_primenum(int l, int r){
    // TODO
 bool stop=false;
    while(l<r && !stop){
    	int flag=0;
    	for(int i=2;i<=l/2;i++){
    		if(l%i==0)
    		{
    			flag=1;
    			break;
			}
		}
		if(flag==0 && l!=1 && l!=0){
			cout<<l;
			stop=true;
		}
		++l;
	}
	while(l<r){
		int flag=0;
		for(int i=2;i<=l/2;i++){
			if(l%i==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0 && l!=1 && l!=0)
		cout<<" "<<l;
		++l;
	}
    cout<<"\n";
}

int main(int arg, char** argv){
    ifstream ifs;
	ifs.open(argv[1]);
	int l, r;
	try
	{
		ifs >> l >> r;
        print_primenum(l , r);
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}