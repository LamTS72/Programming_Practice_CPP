#include <iostream>
using namespace std;

/* ============= FUNCTION ===========*/
double factorialFunc(int n){
    if(n == 0 || n == 1) return 1;
    int result = 1;
    for (int i = n; i > 0; i--){
        result *= i;
    }
    return result;
}

int findMax(int *vals, int numEls) {
    // TODO
    int maxVal = vals[0];
    for(int i = 1; i < numEls ; i++){
        if(maxVal < vals[i]){
            maxVal = vals[i];
        }
    }
    return maxVal;
}

void sum2(int * array, int numEls, int &result)
{
    // TODO
    int sumVal = 0;
    for(int i = 0; i < numEls ; i++){
        sumVal += array[i];
    }
    cout << result << endl;
    result = sumVal;
    cout << result << endl;
}
bool completeNum(int N)
{
    // TODO
    if(N <= 0) return false;
    int result = 0;
    for(int i = 1; i < N; i++){
        if(N % i == 0){
            result += i;
        }
    }
    if(N == result){
        return true;
    }
    return false;
}
bool isPalindrome(const char* str) {
    // Write your code here
    size_t length = 0;
    int i = 0;
    while(str[i] != '\0'){
        length++;
        i++;
    }
    for(int i = 0; i < length; i++){
        if(str[i] != str[length - i - 1]){
            return false;
        }
    }
    return true;
}
bool checkPrime(int n){
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
bool isSpecialNumber(int n) {
    // Write your code
    if(checkPrime(n) == false) return false;
    int temp = n;
    int sum = 0;
    while(temp != 0){
        int digit = temp % 10;
        sum += digit;
        temp = temp / 10;
    }
    if(checkPrime(sum) == false) return false;
    return true;
}
void encrypt(char* text, int shift) {
    // Write your code
    while(shift < 0){
        shift += 26;
    }
    for(int i = 0; text[i] != '\0'; i++){
        if(text[i] >= 'a' && text[i] <= 'z'){
            text[i] = char(int(text[i] + shift - 97) % 26 + 97);
        }
        if(text[i] >= 'A' && text[i] <= 'Z'){
            text[i] = char(int(text[i] + shift - 65) % 26 + 65);
        }
    }
}

void decrypt(char* text, int shift) {
    // Write your code
    encrypt(text,-shift);
}

bool checkElementsUniqueness(int* arr, int n) {
    // Write your code
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] == arr[j]){
                return false;
            }
        }
    }
    return true;
}

long int decimalToBinary(int decimal_number){
//    int base = 1;
//    long int sum = 0;
//    while(decimal_number != 0){
//        sum += (decimal_number%2)*base;
//        base = base * 10;
//        decimal_number = decimal_number/2;
//    }
//    return sum;
    if (decimal_number == 0)
           return 0;
    else
       return (decimal_number % 2 + 10 * decimalToBinary(decimal_number / 2));
    // 10 => 0 + 10*(1 + 10*(0 + 10*(1 + 10*0))) = 1010
}
int numberOfDiffCharac(string str){
#include <string>
    int result = 0;
    string sArray = "";
    for(int i = 0; str[i] != '\0'; i++){
        if(i == 0){
            sArray.insert(sArray.end(), str[i]);
            result++;
        }
        else{
            bool flag = false;
            for(int j = 0; sArray[j] != '\0' ;j++){
                if(sArray[j] == str[i]){
                    flag = true;
                    break;
                }
            }
            if(flag == false){
                sArray.insert(sArray.end(), str[i]);
                result++;
            }
        }
    }
    return result;
}
/* ============= ARRAY ===========*/
int findMaxColumn(int arr[][1000], int row, int col) {
    int maxCol = 0;
    int index = 0;
    for(int j = 0; j < col ; j++){
        int sumCol = 0;
        for (int i = 0; i < row; i++){
            sumCol += arr[i][j];
        }
        if(j == 0){
            maxCol = sumCol;
        }
        else{
            if(maxCol < sumCol){
                maxCol = sumCol;
                index++;
            }
        }
    }
    return index;
}
int diagonalProduct(int arr[][1000], int row, int col) {
    int product = 1;
    for(int i = 0; i < row; i++){
        product *= arr[i][i];
    }
    return product;
}
bool isSymmetric(int arr[][1000], int row, int col) {
    for (int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(arr[i][j] != arr[j][i]){
                return false;
            }
        }
    }
    return true;
}
int diagonalDiff(int arr[][1000], int row, int col, int x, int y) {
    int sum1 = 0; // Sum of diagonal 1
    int sum2 = 0; // Sum of diagonal 2

    // Calculate the sum of diagonal 1
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i - j == x - y) {
                sum1 += arr[i][j];
            }
        }
    }

    // Calculate the sum of diagonal 2
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i + j == x + y) {
                sum2 += arr[i][j];
            }
        }
    }
    int result = sum1 - sum2;
    if(result < 0){
        result = -result;
    }
    return result;
}
int ascendingRows(int arr[][1000], int row, int col) {
    int count = 0;
    for(int i = 0; i < row; i++){
        bool flag = false;
        for (int j = 0; j < col - 1; j++){
            if(arr[i][j] > arr[i][j+1]){
                flag = true;
                break;
            }
        }
        if(flag == false){
            count++;
        }
    }
    return count;
}
int primeColumns(int arr[][1000], int row, int col) {
    int count = 0;
    for(int j = 0; j < col ; j++){
        int sumCol = 0;
        for (int i = 0; i < row; i++){
            sumCol += arr[i][j];
        }
        if (checkPrime(sumCol)){
            count++;
        }
    }
    return count;
}
/* ============= FILE IO ===========*/
#include <fstream>
#include <string>
void calSum(string fileName)   {
    // TODO
    ifstream myfile;
    myfile.open(fileName);
    int sum = 0;
    int num;
    while(myfile >> num){
        sum = sum + num;
    }
    myfile.close();   // closing the file
    cout<<sum;
    
}
void uppercase(string output)   {
    // TODO
    string input;
    cin >> input;
    for(int i = 0; input[i] != '\0'; i++){
        if(input[i] >= 'a' && input[i] <= 'z'){
            input[i] = input[i] - 32;
        }
    }
    ofstream myfile;
    myfile.open(output);
    string temp = input;
    myfile << temp;
    myfile.close();
}
void threeChars(string fileName)   {
    // TODO
    ifstream myfile;
    myfile.open(fileName);
    string line;
    while (myfile >> line) {
        if(line[0] <= line[1] && line[1] <= line[2]){
            if(line == "***"){
                break;
            }
            cout<<"true"<<endl;
        }
        else{
            cout<<"false"<<endl;
        }
    }
}
void process(string fileName)   {
    // TODO
    ifstream myfile;
    myfile.open(fileName);
    string line;
    getline(myfile, line);
    int start = 0;
    int row = 0;
    int col = 0;
    bool flag = false;
    while(start < line.length()){
        while(start < line.length() && (line[start] > '9' || line[start] < '0')){
            start++;
            flag = true;
        }
        if(start >= line.length()){
            break;
        }
        if(flag == false){
            while (start < line.length() && line[start] <= '9' && line[start] >= '0') {
                row = row * 10 + line[start] - '0';
                start++;
            }
        }
        else{
            while (start < line.length() && line[start] <= '9' && line[start] >= '0') {
                col = col * 10 + line[start] - '0';
                start++;
            }
        }
    }
    double arr[row][col];
    double num;
    for(int i = 0; i < row; i++){
        for(int j = 0; j< col; j++){
            myfile >> num;
            arr[i][j] = num;
        }
    }
    double maxTotal = arr[0][0];
    for(int i = 0; i < row; i++){
        double maxRow = arr[i][0];
        for(int j = 0; j< col; j++){
            if(arr[i][j] >= maxRow){
                maxRow = arr[i][j];
            }
            if(arr[i][j] >= maxTotal){
                maxTotal = arr[i][j];
            }
        }
        cout << maxRow << " ";
    }
    cout << maxTotal;
    myfile.close();
}
/* ============= RECURSIVE ===========*/
int gcdRecursion(int p, int q)
{
    // BEGIN YOUR IMPLEMENTATION [1]
    // TODO
    if(p == 0 || q == 0) return p + q;
    if(p == q) return p;
    if(p > q) return gcdRecursion(p - q, q);
    else return gcdRecursion(p, q - p);
    // END YOUR EMPLEMENTATION [1]
}

int gcdIteration(int p, int q)
{
    
    // BEGIN YOUR IMPLEMENTATION [2]
    // TODO
    if(p == 0 || q == 0){
        return p+q;
    }
    while(p != q){
        if(p > q){
            p -= q;
        }
        else{
            q -= p;
        }
    }
    return p;
    
    // END YOUR EMPLEMENTATION [2]
}
int strLen(char* str)
{
    if(*str == '\0'){
        return 0;
    }
    else{
        return 1 + strLen(str + 1);
    }
}
void printPattern(int n)
{
    int temp = 5;
    if(n > 0){
        cout << n << " ";
        printPattern(n - temp);
    }
    else{
        cout << n;
        temp = -temp;
        return;
    }
    cout <<" " <<n;
}
bool checkDuplicate(int* ar,int size)
{
  //Implement content in function  here
//    for(int i = 0; i < size - 1; i++){
//        for (int j = size - 1; j > i; j--){
//            if(ar[i] == ar[j]){
//                return false;
//            }
//        }
//    }
//    return true;
    if (size <= 1)
        return true;

    for (int i = 0; i < size - 1; i++)
    {
        if (ar[i] == ar[size - 1])
            return false;
    }

    return checkDuplicate(ar, size - 1);
}
int recursiveSearch(int& n , int m, int arr[], int index)
{
   // Implement function content here
    if (index >= n)
        return -1;

    if (arr[index] == m){
        for (int i = index; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        n--;
        return index;

    }
        

    return recursiveSearch(n, m, arr, index + 1);
}
/* ============= POINTER ===========*/
int getValueAtIndex(int *ptr, int k)
{
    int idx = 0;
    while(ptr != nullptr){
        if(idx == k){
            return *ptr;
        }
        idx++;
        ptr++;
    }
    return -1;
}
void swap(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
int calcSum(int *ptr, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += *(ptr+ i);
    }
    return sum;
}
void add(int *ptr, int n, int k){
    *(ptr+n) = k;
}
int** readArray()
{
   //TODO
    int** matrix = new int*[10];

    for (int i = 0; i < 10; i++) {
        matrix[i] = new int[10];
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 0) {
                for (int k = j + 1; k < 10; k++) {
                    matrix[i][k] = 0;
                }
                break;
            }
        }
    }

    return matrix;
}
void addElement(int*& arr, int n, int val, int index) {
    // TODO
    int* newArr = new int[n + 1];
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    newArr[index] = val;
    for (int i = index + 1; i < n + 1; i++) {
        newArr[i] = arr[i - 1];
    }

    delete[] arr;
    arr = newArr;
}
int main(int argc, const char * argv[]) {
    cout << readArray();
    cout << endl;
    return 0;
}
