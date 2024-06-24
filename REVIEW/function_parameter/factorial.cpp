#include <iostream>
#include <fstream>
using namespace std;
// implement calculate factorial in here
// TODO
int calculateFactorial(int a){
	int fact = 1;
	for ( int i = 1; i <= a ; i++ ){
		fact *= i;
	}
	a = fact;
	return a;
}
int main(int narg, char** argv)
{
	ifstream ifs;
	ifs.open(argv[1]);
	int N;
	try
	{
		ifs >> N;
		long result;
		// call function calculateFactorial in here and assign value to the variable result
		// TODO
result = calculateFactorial(N);
		cout << result << endl;
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}