#include <iostream>
#include <fstream>
using namespace std;
void Fibonacci(int n) {
	// TODO
int f1=1,f2=1,fn;
	if(n==1 || n==2)
			fn=1;
			
	for(int i=3;i<=n;i++){
		fn=f1+f2;
		f1=f2;
		f2=fn;
	}
		cout<<fn;
		cout<<"\n";
	
}
int main(int narg, char** argv)
{
	ifstream ifs;
	ifs.open(argv[1]);
	int a;
	try
	{
		while (ifs >> a)
		{
			Fibonacci(a);
		}
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
