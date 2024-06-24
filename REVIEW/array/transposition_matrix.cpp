#include <iostream>
#include <fstream>
using namespace std;

// matrix is two dimensional array. You should transposition matrix
void transposition(int rows, int cols, int **matrix) {
	// TODO
	int transpose[cols][rows];
	 for(int i=0;i<rows;i++)
	 {
	 	for(int k=0;k<cols;k++)
	 		transpose[k][i]=matrix[i][k];
	 }
	 cout<<transpose[0][0];
	 for(int k=1;k<rows;k++)
	 cout<<" "<<transpose[0][k];
	 for(int i=1;i<cols;i++){
	 cout<<endl;
	 cout<<transpose[i][0];
	 for(int k=1;k<rows;k++)
	 {
	 cout<<" "<<transpose[i][k];
}
}
cout<<"\n";
}
int main(int narg, char** argv)
{
	ifstream ifs;
	ifs.open(argv[1]);
	
	int rows;
	int cols;
	ifs >> rows;
	ifs >> cols;
	int** matrix = new int*[rows];
	try
	{
		int i = 0;
		int j = 0;
		for (int i = 0; i < rows; i++) {
			matrix[i] = new int[cols];
			for (int j = 0; j < cols; j++) {
				ifs >> matrix[i][j];
			}
		}
		transposition(rows, cols, matrix);
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
