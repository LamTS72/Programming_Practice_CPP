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
/* ============= CLASS OOP ===========*/
class ClockType
{
public:
    ClockType(int, int, int);
    ClockType();
    void printTime() const;
    void setTime(int, int, int);
    void getTime(int&, int&, int&) const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const ClockType&) const;
private:
    int hr;
    int min;
    int sec;
};

void ClockType::printTime() const
{
   if (hr < 10)
      cout << "0";
   cout << hr << ":";
   if (min < 10)
      cout << "0";
   cout << min << ":";
   if (sec < 10)
      cout << "0";
   cout << sec;
}

// TODO
ClockType::ClockType(int h, int m, int s){
    if(0 <= h && h <= 24){
        this->hr = h;
    }
    else{
        this->hr = 0;
    }
    if(0 <= m && m <= 60){
        this->min = m;
    }
    else{
        this->min = 0;
    }
    if(0 <= s && s <= 60){
        this->sec = s;
    }
    else{
        this->sec = 0;
    }
}
ClockType::ClockType(){
    this->hr = 0;
    this->min = 0;
    this->sec = 0;
}
void ClockType::setTime(int h , int m, int s){
    if(0 <= h && h <= 24){
        this->hr = h;
    }
    else{
        this->hr = 0;
    }
    if(0 <= m && m <= 60){
        this->min = m;
    }
    else{
        this->min = 0;
    }
    if(0 <= s && s <= 60){
        this->sec = s;
    }
    else{
        this->sec = 0;
    }
}
void ClockType::getTime(int &h, int& m, int& s) const{
    h = this->hr;
    m = this->min;
    s = this->sec;
}
void ClockType::incrementHours(){
    if(this->hr < 24){
        this->hr++;
        if(this->hr == 24){
            this->hr = 0;
        }
    }
}
void ClockType::incrementMinutes(){
    if(this->min < 60){
        this->min++;
        if(this->min == 60){
            this->min = 0;
            incrementHours();
        }
    }
}
void ClockType::incrementSeconds(){
    if(this->sec < 60){
        this->sec++;
        if(this->sec == 60){
            this->sec = 0;
            incrementMinutes();
        }
    }
}
bool ClockType::equalTime(const ClockType& other) const{
    if(other.hr != this->hr) return false;
    if(other.min != this->min) return false;
    if(other.sec != this->sec) return false;
    return true;
}

class Course {
private:
    int ID;
    int numOfStudent;
    int numOfTeacher;
    int numOfTA;
public:
    void getinfo();
    void disinfo();
};

void Course::getinfo() {
   cout << "ID: ";
   cin >> ID;
   cout << "Number of Students: ";
   cin >> numOfStudent;
   cout << "Number of Teachers: ";
   cin >> numOfTeacher;
   cout << "Number of TAs: ";
   cin >> numOfTA;
}

void Course::disinfo()
{
   cout<<endl;
   cout<< "CourseID = "<< ID << endl;
   cout<< "Number of student = " << numOfStudent << endl;
   cout<< "Number of teacher = " << numOfTeacher << endl;
   cout<< "Number of TA = " << numOfTA<< endl;
}

class Room{
private:
    double length;
    double breadth;
    double height;
public:
    Room(double length, double breadth, double height);
    double calculateArea();
    double calculateVolume();
};
Room::Room(double length, double breadth, double height){
    this->length = length;
    this->breadth = breadth;
    this->height = height;
}
double Room::calculateArea(){
    return this->length * this->breadth;
}
double Room::calculateVolume(){
    return this->length * this->breadth * this->height;
}

template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();

    void setAt(int idx, const T & value);
    T getAt(int idx);
    T& operator[](int idx);
    Array(const Array<T>& other);
    Array<T>& operator=(const Array<T> & other);
    void print();

private:
    int size;
    T * p;
};

template<typename T>
void Array<T>::print() {
    for (int i = 0; i < this->size; ++i) {
        cout << (i > 0 ? " " : "")
            << this->p[i];
    }
    cout << endl;
}

// TODO
template <typename T>
Array<T>::Array(int size, T initValue) {
    this->size = size;
    p = new T[size];
    for (int i = 0; i < size; i++) {
        p[i] = initValue;
    }
}
template <typename T>
Array<T>::~Array() {
    delete[] p;
}
template<typename T>
T& Array<T>::operator[](int idx){
    if(idx < 0 || idx >= size){
        throw -1;
    }
    return p[idx];
}
//template<typename T>
//Array<T>::Array(const Array<T>& other){
//    this->size = other.size;
//    p = new T[this->size];
//    for(int i = 0; i < this->size; i++){
//        p[i] = other.p[i];
//    }
//}
template <typename T>
Array<T>::Array(const Array<T>& other){
    this->size = other.size;
    p = new T[this->size];
    for(int i = 0; i < this->size; i++){
        p[i] = other.p[i];
    }
    cout << "Call copy constructor"<<endl;
}
template<typename T>
Array<T>& Array<T>::operator=(const Array<T> & other){
    if(this != &other){
        delete p;
        this->size = other.size;
        p = new T[this->size];
        for(int i = 0; i < this->size; i++){
            p[i] = other.p[i];
        }
    }
    cout<<"Call assignment operator"<<endl;
    return *this;
}


class Integer{
private:
    int val;
public:
    Integer(int val);
    void setValue(int value);
    int getValue();
    Integer(Integer *val);
    Integer operator+(const Integer&) const;
    Integer operator+(int val) const;
    void print();
};
Integer::Integer(int val){
    this->val = val;
}
void Integer::setValue(int value){
    this->val = value;
}
int Integer::getValue(){
    return this->val;
}
Integer::Integer(Integer *other){
    this->val = other->val;
}
Integer Integer::operator+(const Integer& other) const{
    return Integer(other.val + this->val);
}
Integer Integer::operator+(int val) const{
    return Integer(this->val + val);
}
void Integer::print() {
    cout << this->val << endl;
}

class Book {
    char* name;
public:
    Book(const char*);
    ~Book();
    
    void display();
    char* getName();
};
#include <string.h>
Book::Book(const char* input){
    name = new char[strlen(input)];
    for(int i = 0; i < strlen(input); i++){
        name[i] = input[i];
    }
}
Book::~Book(){
    delete[] name;
}
void Book::display() {
    cout << "Book: " << this->name << endl;
}

char* Book::getName() {
    return this->name;
}


template < class T >
class Cell {
       protected:
           T infor;
       public:
           void set(T x){ infor = x; }
           T get() { return infor; }
   };
enum Color {White, Yellow, Black, Red, Blue};

template < class T >
class ColoredCell:public Cell<T>{
protected:
    Color color;
public:
    void setColor(Color );
    Color getColor();
    T* get();
};

template < class T >
void ColoredCell<T>::setColor(Color c){
    this->color = c;
}

template < class T >
Color ColoredCell<T>::getColor(){
    return this->color;
}
template < class T >
T* ColoredCell<T>::get(){
    if(this->color != White){
        return &(this->infor);
    }
    else{
        return NULL;
    }
}

int main(int argc, const char * argv[]) {
    int x, y, z;
    cin >> x >> y >> z;
    Integer a(x);
    Integer b(y);
    Integer* t = new Integer(z);
    Integer c(t);
    
    a.print(); b.print();
    (a + b + c + 4).print();
    
    delete t;
    return 0;
}
