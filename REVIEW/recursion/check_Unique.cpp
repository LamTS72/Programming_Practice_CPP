#include <iostream>
#include <fstream>
using namespace std;
bool uniqueElement(int size, int *a, int i)
{
	// TODO
for ( int i = 1; i < size; i++){
		for ( int j = 0; j < i; j++){
			if ( a[i] == a[j] ){
				return false;
			}
		}
	}
	return true;
}

int main(int narg, char** argv)
{
	
	ifstream ifs;
	ifs.open(argv[1]);

	int size;
	ifs >> size;
    int i = 0;
	int *a = new int[size];
	try {

		while (ifs >> a[i])
		{
			i++;
		}
		cout << uniqueElement(size, a, 0) << endl;
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
