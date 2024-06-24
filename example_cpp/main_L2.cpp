#include <iostream>
//#include<cstring>
#include<fstream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
//============================LAB_2==================================
//RECURSION_PRELAB
int gcdRecursion(int p, int q){
    if(p==0 || q==0 )
        return p+q;
    if(p==q)
        return p;
    if(p>q)
        return gcdRecursion(p-q,q);
    else return gcdRecursion(p,q-p);
}
int gcdIteration(int p, int q)
{
   // if(p == 0 && q == 0) return 0;
    if (p == 0 || q == 0){
            return p + q;
        }
    while (p != q){
            if (p > q){
                p -= q;
            }else{
                q -= p;
            }
        }
        return p;
}
int strLen(char* str)
{
    if (*str == '\0')
        return 0;
    else
        return 1 + strLen(str + 1);
}
void printPattern(int n)
{
    int temp = 5;
    if(n <= 0){
        temp = -temp;
        cout <<n;
        return;
    }
    else{
        //if(n - temp > 0)
        cout << n <<",";
        //else cout << n;
        printPattern(n - temp);
    }
    
    cout <<"," <<n;

}
//POINTER BASIC_PRELAB
int getValueAtIndex(int *ptr, int k)
{
    int idx = 0;
    while(ptr != NULL){
        if(idx == k){
            return *ptr;
        }
        idx++;
        ++ptr;
    }
    return -1;
}
void swap(int *ptr1, int *ptr2)
{
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
int* zeros(int n) {
    if(n <= 0) return nullptr;
    int *array = new int[n];
    for(int i= 0; i < n ;i++){
        array[i] = 0;
    }
    return array;
}
void shallowCopy(int*& newArr, int*& arr) {
    // TODO
    newArr = arr;
}

int** deepCopy(int** matrix, int r, int c) {
    // create a new matrix with the same dimensions
    if(r <= 0 || c <= 0) return nullptr;
    int** newMatrix = new int*[r];
    for (int i = 0; i < r; i++) {
        newMatrix[i] = new int[c];
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            newMatrix[i][j] = matrix[i][j];
        }
    }
    
    // return the new matrix
    return newMatrix;
}
void deleteMatrix(int**& matrix, int r) {
    for (int i = 0; i < r; i++) {
        delete[] matrix[i];
    }
    
    delete[] matrix;
    matrix = NULL;
    cout <<"SUCCESSFUL";
}
void insertRow(int**& matrix, int r, int c, int* rowArr, int row) {
    // create a new matrix with an additional row
    int** newMatrix = new int*[r + 1];
    for (int i = 0; i < r + 1; i++) {
        newMatrix[i] = new int[c];
    }
    
    // copy the elements before the insertion point
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < c; j++) {
            newMatrix[i][j] = matrix[i][j];
        }
    }
    
    // copy the inserted row
    for (int j = 0; j < c; j++) {
        newMatrix[row][j] = rowArr[j];
    }
    
    // copy the elements after the insertion point
    for (int i = row; i < r; i++) {
        for (int j = 0; j < c; j++) {
            newMatrix[i + 1][j] = matrix[i][j];
        }
    }
    
    // free the memory for the old matrix
    deleteMatrix(matrix, r);
    
    // update the matrix pointer to point to the new matrix
    matrix = newMatrix;
}
//STRUCT_PRELAB
struct SCP {
    int id;
    int objClass;
    string speConProcedures;
    string description;
    string* addendums;
    int numAddendums;
};
void addAddendum(SCP &obj, string addendum) {
    // Student answer
    
    string* addendums = obj.addendums;
    string* newAddendums = new string[obj.numAddendums + 1];
    for(int i = 0; i < obj.numAddendums;i++){
        newAddendums[i] = addendums[i];
    }
    newAddendums[obj.numAddendums] = addendum;
        
        // free the old array memory and assign the new one to obj.addendums
    delete[] addendums;
    obj.addendums = newAddendums;
        
        // increment the numAddendums count
    obj.numAddendums++;
}
//================================================

int main(int argc, const char * argv[]) { // FOR LAB 2
    
    int p,q;
    cin>>p>>q;
    cout<<gcdRecursion(p,q)<< " "<<gcdIteration(p,q);
    char str[] = "Truong DH Bach Khoa";
    cout << strLen(str);
    printPattern(16);
    cout<<"||";
    cout << endl;
    printPattern(-1);
    int arr[] = {1, 2, 3, 4, 5};
    int k = 3;
    cout << getValueAtIndex(arr, k);
    int a = 5;
    int b = 6;
    swap(&a, &b);
    cout << a << ' ' << b;
    int *arr = zeros(-1);
    cout<< *arr;
    int* arr = new int[2];
    arr[0] = 2; arr[1] = 3;
    int* newArr = nullptr;
    shallowCopy(newArr, arr);
    cout << newArr[0] << ' ' << newArr[1];
    delete[] arr;
    
    int** m = new int*[3];
    m[0] = new int[2]; m[0][0] = 2; m[0][1] = 2;
    m[1] = new int[2]; m[1][0] = 1; m[1][1] = 1;
    m[2] = new int[2]; m[2][0] = 1; m[2][1] = 1;
    int** n = deepCopy(m, 3, 2);
    cout << n[0][0] << ' ' << n[0][1] << '\n' << n[1][0] << ' ' << n[1][1]<< '\n' << n[2][0] << ' ' << n[2][1];
    deleteMatrix(n, 3);
    string* addendums = new string[1];
    addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";

    SCP obj {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 1};

    addAddendum(obj, "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.");

    cout << obj.addendums[1];

   delete [] obj.addendums;
    return 0;
    
}
