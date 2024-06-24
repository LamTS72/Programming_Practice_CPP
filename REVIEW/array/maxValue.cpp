#include <iostream>
#include <fstream>
using namespace std;
void maxValue(int n, double *a) {
	// TODO
double max=a[0];
	for(int i=1;i<n;i++)
	
		if(max<a[i])
		max=a[i];
	
	cout<<max;
	cout<<"\n";
}
int main(int narg, char** argv)
{
	ifstream ifs;
	ifs.open(argv[1]);

	int size;
	ifs >> size;
	ifs.ignore(1, '\n');
    int i = 0;
	double *a = new double[size];
	try {

		while (ifs >> a[i])
		{
			i++;
		}
		maxValue(size, a);
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
