#include <iostream>
#include <fstream>
using namespace std;
int permutation(int n, int m) {
	// TODO
if(m>=0 && m<= n){
		if(n>=1){
			if(m==0 || m==n)
			return 1;
		}
	}
	else if(n>=0 && n<= m){
		if(m>=1){
			if(n==0 || n==m)
			return 1;
		}
	}
	 if(m>0 && m<n)
		return permutation( n-1, m) + permutation( n-1, m-1);
	else 
		return permutation( n, m-1) + permutation( n-1, m-1);
}
int main(int narg, char** argv)
{
	ifstream ifs;
	ifs.open(argv[1]);
	int N;
	int M;
	try
	{
		ifs >> N;
		ifs >> M;
		cout << permutation(N, M) << endl;
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
